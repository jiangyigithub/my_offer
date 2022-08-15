#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <mosquitto.h>

#include "cJSON.h"

#define PORT 1883
#define HOST "localhost"
#define TOPIC "test_topic"

void mosq_connect_cb(struct mosquitto *mosq, void *obj, int rc)
{
    int rv;
    char value[6] = "Bosch";
    cJSON *root;
    cJSON *item;
    char *msg;

    /* Create a JSON Object */
    root = cJSON_CreateObject();
    if (root == NULL) {
        printf("internel error. JSON Object Create fail\n");
        return;
    }

    /* Create a JSON value*/
    item = cJSON_CreateString(value);
    if (item == NULL) {
        printf("internel error. create JSON String error.\n");
        return;
    }

    /* write the kay and value into the json object */
    cJSON_AddItemToObject(root, "company", item);

    /* parser to string */
    msg = cJSON_Print(root);
    printf("msg: %s\n", msg);

    //int mosquitto_publish( struct mosquitto * mosq, int * mid, const char * topic, int payloadlen, const void * payload, int qos, bool retain )

    rv = mosquitto_publish(mosq, NULL, TOPIC, strlen(msg), msg, 0, 0);
    if (rv != 0) {
        printf("pub mqtt topic fail\n");
        return;
    }

    /* disconnect the mqtt server */
    mosquitto_disconnect(mosq);

    return;
}

int main(int argc, int **argv)
{
    int rv;
    struct mosquitto *mosq;

    /* step1: init */
    mosq == NULL;
    rv = mosquitto_lib_init();
    if (rv != MOSQ_ERR_SUCCESS) {
        printf("init mosquitto lib fail!, rv = %d\n", rv);
        return rv;
    }
    printf("init mqtt lib success!\n");

    /* step2: create mosquitto client */
    mosq = mosquitto_new(NULL, true, NULL);
    if (mosq == NULL) {
        printf("Create mosquitto client fail!, rv = %d\n", rv);
        /* destory and clean lib */
        mosquitto_lib_cleanup();
        return rv;
    }
    printf("create mosquitto client success.\n");

    /* step3: set the calback function */
    mosquitto_connect_callback_set(mosq, mosq_connect_cb);

    /* step4: connect mqtt server  */
    while (1) {
        rv = mosquitto_connect(mosq, HOST, PORT, 60);
        if (rv != MOSQ_ERR_SUCCESS) {
            printf("connect mqtt server fail!, rv = %d\n", rv);
            mosquitto_destroy(mosq);
            mosquitto_lib_cleanup();
            return rv;
        }
        printf("connect mqtt server success.\n");
        mosquitto_loop_forever(mosq, -1, 1);
        sleep(10);
    }

    return 0;
}

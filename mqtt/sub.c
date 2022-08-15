#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mosquitto.h>

#define HOST "localhost"
#define PORT 1883
#define TOPIC "test_topic"

/* callback function */
void mqtt_connect_cb(struct mosquitto *mosq, void *obj, int rc)
{
    int rv;

    if(rc) {
        printf("set connect cb function error!\n");
        exit(1);
    } 
    printf("Set connect cb function success!\n");

    /* sub topic */
    rv = mosquitto_subscribe(mosq, NULL, TOPIC, 2);
    if (rv) {
        printf("Fail to subscribe topic\n");
        exit(1);
    }

    printf("sub topic success!\n");
    return;
}

/* handle the message */
void mqtt_message_cb(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
    /* just print the payload */
    if (msg == NULL) {
        printf("param error!\n");
        return;
    }
    
    printf("Recieving message successfully\n");
    printf("The message is:%s\n", (char *)msg->payload);

    return;
}

int main()
{
    int rv;
    struct mosquitto *mosq;

    /* lib init */
    rv = mosquitto_lib_init();
    if (rv != MOSQ_ERR_SUCCESS) {
        printf("init mosquitto lib fail.\n");
        return 1;
    }
    printf("init mqtt lib success!\n");

    /* create client */
    mosq = mosquitto_new(NULL, true, NULL);
    if (mosq == NULL) {
        printf("mosquitto client create fail! rv = %d\n", rv);
        mosquitto_lib_cleanup();
        return rv;
    }
    printf("create mqtt client success!\n");

    /* set callback */
    mosquitto_connect_callback_set(mosq, mqtt_connect_cb);
    mosquitto_message_callback_set(mosq, mqtt_message_cb);

    /* connect broker */
    rv = mosquitto_connect(mosq, HOST, PORT, 60);
    if (rv != MOSQ_ERR_SUCCESS) {
        printf("connect to mqtt broker fail!, rv = %d\n", rv);
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return rv;
    }

    printf("connect mqtt broker success!\n");

    while (1) {
        /* waitting message */
        mosquitto_loop(mosq, -1, 1);
    }
    return 0;
}
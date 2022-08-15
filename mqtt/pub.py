# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    print("Connected with result code: " + str(rc))

def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.payload))

client = mqtt.Client()
#设置用户名和密码
client.username_pw_set("mosquitto", "mosquitto")
client.on_connect = on_connect
client.on_message = on_message
#连接 IP port keepalive
client.connect('localhost', 1883, 600)
# client.connect('broker-cn.emqx.io', 1883, 600)
# client.connect('test.mosquitto.org', 1883, 600)
#发布 topic 内容
client.publish('test', payload='amazing mqtt python', qos=0)
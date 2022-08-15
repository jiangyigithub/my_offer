

# setup linux env
https://zhuanlan.zhihu.com/p/164930347?ivk_sa=1024320u
http://www.steves-internet-guide.com/install-mosquitto-linux/

# broker type
https://www.catchpoint.com/network-admin-guide/mqtt-broker

# client API
https://docs.emqx.com/en/enterprise/v4.4/development/c.html#paho-c-usage-example


# 1. broker install, use 'mosquitto' as an  local broker example
- install
```
sudo apt-get install mosquitto   --> broker
sudo apt-get install mosquitto-clients --> client
```

- start server
```
mosquitto -c /etc/mosquitto/mosquitto.conf -d
mosquitto -p 1883
sudo service mosquitto start
sudo service mosquitto stop
```

- check process state and networking state
```bash process
sudo kill -9 $(pidof mosquitto)
ps -aux | grep mosquitto
```

```bash networking
netstat -ntpl
```


# 2. create client demo
- by  C API
- by python API
- by online websocket client
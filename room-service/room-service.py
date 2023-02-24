import json
import paho.mqtt.client as paho
import requests as req

def on_subscribe(client, userdata, mid, granted_qos):
    print("Subscribed: "+str(mid)+" "+str(granted_qos))


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("occupance", qos=1)
    
def callback(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.qos)+" "+str(msg.payload))
    decoded_message = msg.payload.decode("utf-8")
    msg = json.loads(decoded_message)
    req.post(url, json=msg)

client = paho.Client()
client.on_connect = on_connect
# client.connect("broker.hivemq.com", 1883)
client.on_subscribe = on_subscribe
client.on_message = on_message
url = "http://localhost/assignment-03/room-dashboard/room-dashboard-history.php"
req.post(url, json={"room": "1", "occupance": "1"})

# client.loop_forever()

print("Starting loop")


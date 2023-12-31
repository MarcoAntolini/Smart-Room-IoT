#include "execute.h"

execute::execute(pir* p, led* l, photoresistor* ph, PubSubClient* client, const char* topic) {
    this->p = p;
    this->l = l;
    this->ph = ph;
    this->client = client;
    this->topic = topic;
}

void execute::init(int period) {
    Task::init(period);
}

void execute::tick() {
    StaticJsonDocument<200> doc;
    bool isMotion = p->isMotion();
    if(ph->getLight() < 2000 && isMotion){
        doc["lights"] = "On";
    } else {
        doc["lights"] = "Off";
    }
    Serial.println(digitalRead(19));
    doc["lightLevel"] = analogRead(32);
    doc["isMotion"] = isMotion;
    serializeJson(doc, Serial);
    Serial.println();

    char buffer[256];
    serializeJson(doc, buffer);
    client->publish(this->topic, buffer);

    if(isMotion){
        l->on();
    } else {
        l->off();
    }
}

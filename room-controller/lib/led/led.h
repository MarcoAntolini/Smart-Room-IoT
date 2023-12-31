#ifndef __LED__
#define __LED__

#include <Arduino.h>

class Led
{
public:
    Led(int pin);
    void initialize();
    void on();
    void off();
    void toggle();
    bool isOn();

private:
    int _pin;
    bool _state;
};

#endif
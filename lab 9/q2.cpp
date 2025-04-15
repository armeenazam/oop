#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
public:
    SmartDevice() {}
    virtual bool turnOn() = 0;
    virtual bool turnOff() = 0;    
    virtual bool getStatus() = 0;
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;
public:
    LightBulb(int b) : brightness(b), isOn(false) {}

    bool turnOn() override {
        isOn = true;
        return true;
    }

    bool turnOff() override {
        isOn = false;
        return true;
    }

    bool getStatus() override {
        return isOn;
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;
public:
    Thermostat(double t) : temperature(t), isOn(false) {}

    bool turnOn() override {
        isOn = true;
        return true;
    }

    bool turnOff() override {
        isOn = false;
        return true;
    }

    bool getStatus() override {
        return isOn;
    }
};

int main() {
    SmartDevice *s1 = new LightBulb(50);
    SmartDevice *s2 = new Thermostat(38);

    s1->turnOn();
    cout << "LightBulb is " << (s1->getStatus() ? "On" : "Off") << endl;

    s2->turnOff();
    cout << "Thermostat is " << (s2->getStatus() ? "On" : "Off") << endl;

    delete s1;
    delete s2;

    return 0;
}

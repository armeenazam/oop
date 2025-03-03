#include <iostream>
#include <string>
using namespace std;

class Engine {
private:
    int horsepower;
public:
    Engine(int hp = 70) : horsepower(hp) {}
    void display() {
        cout << "Horsepower: " << horsepower << endl;
    }
};

class Wheels {
private:
    int wheelSize;
public:
    Wheels(int size = 14) : wheelSize(size) {}
    void display() {
        cout << "Wheel Size: " << wheelSize << " inches" << endl;
    }
};

class Headlights {
private:
    string lightType;
public:
    Headlights(string type = "LED") : lightType(type) {}
    void display() {
        cout << "Light Type: " << lightType << endl;
    }
};

class Steering {
private:
    string steeringType;
public:
    Steering(string type = "Modern") : steeringType(type) {}
    void display() {
        cout << "Steering Type: " << steeringType << endl;
    }
};

class Car {
private:
    Engine engine;
    Headlights headlights;
    Steering steering;
    Wheels *wheels;
public:
    Car(int hp, string lightType, string steeringType, int wheelSize) 
        : engine(hp), headlights(lightType), steering(steeringType) {
        wheels = new Wheels(wheelSize);
    }

    void display() {
        cout << "===== Car Details =====\n";
        engine.display();
        headlights.display();
        steering.display();
        wheels->display();
        cout << "=======================\n";
    }

    ~Car() {
        delete wheels;
    }
};

int main() {
    Car c(200, "Halogen", "Power", 18);
    c.display();
    return 0;
}

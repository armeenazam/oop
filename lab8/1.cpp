#include <iostream>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceType;
    double powerRating;
    bool status;
    friend class User;

public:
    Device(string id, string type, double rating)
        : deviceID(id), deviceType(type), powerRating(rating), status(false) {}

    virtual void turnOn() {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] turned ON." << endl;
    }

    virtual void turnOff() {
        status = false;
        cout << deviceType << " [ID: " << deviceID << "] turned OFF." << endl;
    }

    virtual double calculatePowerUsage(int hours) = 0;
    string getDeviceType() const { return deviceType; }
};

class Light : public Device {
public:
    Light(string id, string type, double rating) : Device(id, type, rating) {}

    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }
};

class Fan : public Device {
private:
    int speedFactor;

public:
    Fan(string id, string type, double rating, int speed)
        : Device(id, type, rating), speedFactor(speed) {}

    void turnOn() override {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] turned ON at Speed " << speedFactor << "." << endl;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours * speedFactor;
    }
};

class AirConditioner : public Device {
private:
    int desiredTemp;

public:
    AirConditioner(string id, string type, double rating, int temp)
        : Device(id, type, rating), desiredTemp(temp) {}

    void turnOn() override {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] turned ON. Cooling to " << desiredTemp << "°C." << endl;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }
};

class MaintenanceTool;

class SecuritySystem : public Device {
    friend class MaintenanceTool;

public:
    SecuritySystem(string id, string type, double rating) : Device(id, type, rating) {}

    void turnOn() override {
        status = true;
        cout << deviceType << " [ID: " << deviceID << "] activated." << endl;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours;
    }

    friend void accessSecurityLogs(const SecuritySystem &secSys);
};

void accessSecurityLogs(const SecuritySystem &secSys) {
    cout << "Security Logs Accessed:\n";
    cout << "- Intrusion Detected at 3:00 AM\n";
    cout << "- System Reset Required\n";
}

class MaintenanceTool {
public:
    void resetSystem(SecuritySystem &secSys) {
        cout << "Maintenance Personnel Resetting Security Alerts...\n";
    }
};

class User {
private:
    string userID;
    string userRole;
    int accessLevel;

public:
    User(string id, string role, int level) : userID(id), userRole(role), accessLevel(level) {}

    void viewAccessibleDevices(Device *devices[], int size) {
        cout << "User: " << userID << " - Accessible Devices:\n";
        for (int i = 0; i < size; i++) {
            if (devices[i]->getDeviceType() != "Security System" || userRole == "Maintenance Staff") {
                cout << "- " << devices[i]->getDeviceType() << endl;
            }
        }
    }

    void viewSecurityLogs(SecuritySystem &secSys) {
        if (userRole == "Maintenance Staff") {
            accessSecurityLogs(secSys);
        } else {
            cout << "Access Denied! Security logs are restricted to maintenance staff.\n";
        }
    }
};

int main() {
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);

    Device *devices[4] = {&light1, &fan1, &ac1, &secSys1};

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();

    cout << "\nPower Consumption:\n";
    cout << "LED Light: " << light1.calculatePowerUsage(5) << " Watts\n";
    cout << "Ceiling Fan: " << fan1.calculatePowerUsage(3) << " Watts\n";
    cout << "Split AC: " << ac1.calculatePowerUsage(6) << " Watts\n";
    cout << "Security System: " << secSys1.calculatePowerUsage(24) << " Watts\n";

    user1.viewAccessibleDevices(devices, 4);
    user2.viewSecurityLogs(secSys1);

    return 0;
}

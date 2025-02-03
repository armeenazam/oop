#include<iostream>
using namespace std;

class Smartphone{
private:    
    string company;
    string model;
    int displayResolution;
    int RAM;
    int ROM;
    int storage;

public:
    void setCompany(string comp) {
        company = comp;
    }
    string getCompany() const {
        return company;
    }
    void setModel(string mod) {
        model = mod;
    }
    string getModel() const {
        return model;
    }
    void setDisplayResolution(int disRes) {
        displayResolution = disRes;
    }
    int getDisplayResolution() const {
        return displayResolution;
    }   
    void setRAM(int ram) {
       RAM = ram;
    }
    int getRAM() const {
        return RAM;
    }    
    void setROM(int rom) {
       ROM = rom;
    }
    int getROM() const {
        return ROM;
    }   
    void setStorage(int stg) {
       storage = stg;
    }
    int getStorage() const {
        return storage;
    }   

    void phonecall() const {
        cout << "Making a phone call..." << endl;
    }
    void message() const {
        cout << "Sending a message..." << endl;
    }
    void wifi() const {
        cout << "Connecting to the WiFi..." << endl;
    }
    void internet() const {
        cout << "Browsing the internet..." << endl;
    }
};

int main() {
    Smartphone phone1, phone2;
    
    phone1.setCompany("Apple");
    phone1.setModel("iPhone 14");
    phone1.setDisplayResolution(2532);
    phone1.setRAM(6);
    phone1.setROM(128);
    phone1.setStorage(256);
    
    phone2.setCompany("Samsung");
    phone2.setModel("Galaxy S22");
    phone2.setDisplayResolution(2340);
    phone2.setRAM(8);
    phone2.setROM(256);
    phone2.setStorage(512);
    
    cout << "Phone 1 Details:" << endl;
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << "p" << endl;
    cout << "RAM: " << phone1.getRAM() << "GB" << endl;
    cout << "ROM: " << phone1.getROM() << "GB" << endl;
    cout << "Storage: " << phone1.getStorage() << "GB" << endl;
    phone1.phonecall();
    phone1.message();
    phone1.wifi();
    phone1.internet();
    
    cout << "\nPhone 2 Details:" << endl;
    cout << "Company: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Display Resolution: " << phone2.getDisplayResolution() << "p" << endl;
    cout << "RAM: " << phone2.getRAM() << "GB" << endl;
    cout << "ROM: " << phone2.getROM() << "GB" << endl;
    cout << "Storage: " << phone2.getStorage() << "GB" << endl;
    phone2.phonecall();
    phone2.message();
    phone2.wifi();
    phone2.internet();
    
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

class Vehicle{
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r){}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;        
};

class Car : public Vehicle{
public:
    Car(string m, double r) : Vehicle(m,r) {}

    double getDailyRate () override {
        return rate;
    }

    void displayDetails() override{
        cout << "Model: " << model << endl;
        cout << "Rate: $" << rate << endl;
    }
         
};

class Bike : public Vehicle{
public:
    Bike(string m, double r) : Vehicle(m,r) {}

    double getDailyRate () override {
        return rate;
    }

    void displayDetails() override{
        cout << "Model: " << model << endl;
        cout << "Rate: $" << rate << endl;
    }
};

int main(){
    Vehicle *v1 = new Bike ("Honda 70", 20000);
    Vehicle *v2 = new Car ("Maruti Suzuki", 40000);
    v1->getDailyRate();
    v1->displayDetails();
    v2->getDailyRate();
    v2->displayDetails();
    delete v1;
    delete v2;

}
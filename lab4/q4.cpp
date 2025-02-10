// <!-- You are building a car rental system. Create a class `Car` to manage cars available for rent.
// Requirements:
// 1. Attributes:
//  `carID` (int)
//  `model` (string)
//  `year` (int)
//  `isRented` (bool)
// 2. Define a default constructor that initializes `isRented` to `false`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:

//  `rentCar()`: Marks the car as rented.
//  `returnCar()`: Marks the car as available.
//  `isVintage()`: Returns `true` if the car's year is before 2000.

// 5. Create a few `Car` objects and test the methods. -->

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car() {
        isRented = false;
    }

    Car(int carID, string model, int year, bool isRented = false) {
        this->carID = carID;
        this->model = model;
        this->year = year;
        this->isRented = isRented;
    }

    void rentCar() {
        if (isRented) {
            cout << "Car with ID " << carID << " is already rented." << endl;
        } else {
            isRented = true;
            cout << "Car with ID " << carID << " has been rented." << endl;
        }
    }

    void returnCar() {
        if (!isRented) {
            cout << "Car with ID " << carID << " is already available." << endl;
        } else {
            isRented = false;
            cout << "Car with ID " << carID << " has been returned." << endl;
        }
    }

    bool isVintage() {
        return year < 2000;
    }

    void displayDetails() {
        cout << "Car ID: " << carID << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (isRented ? "Rented" : "Available") << endl;
        cout << "Vintage: " << (isVintage() ? "Yes" : "No") << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    Car car1(789, "Audi", 1988);
    Car car2(565, "Honda Civic", 2006);
    Car car3(186, "Hilux", 2014);

    cout << "Initial Car Details:" << endl;
    car1.displayDetails();
    car2.displayDetails();
    car3.displayDetails();

    cout << "Attempting to rent cars:" << endl;
    car1.rentCar();
    car2.rentCar();
    car2.rentCar();

    cout << "Attempting to return cars:" << endl;
    car1.returnCar();
    car1.returnCar();

    cout << "Checking if cars are vintage:" << endl;
    cout << "Car 1 is vintage: " << (car1.isVintage() ? "Yes" : "No") << endl;
    cout << "Car 2 is vintage: " << (car2.isVintage() ? "Yes" : "No") << endl;
    cout << "Car 3 is vintage: " << (car3.isVintage() ? "Yes" : "No") << endl;

    cout << "Final Car Details:" << endl;
    car1.displayDetails();
    car2.displayDetails();
    car3.displayDetails();

    return 0;
}
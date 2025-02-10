// You are building an employee management system. Create a class `Employee` to manage employee
// records.
// Requirements:
// 1. Attributes:
//  `employeeID` (int)
//  `name` (string)
//  `department` (string)
//  `salary` (double)
// 2. Define a default constructor that initializes `salary` to `0.0`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
//  `isManager()`: Returns `true` if the employee's department is "Management".
//  `displayDetails()`: Displays the employee's details.
// 5. Create a few `Employee` objects and test the methods.

#include <iostream>
#include <string>
using namespace std;

class Employee{
private:
    int employeeID;
    string name;
    string department;
    double salary;

public:
    Employee(){
        this->salary=0.0;
    }
    
    Employee(int employeeID, string name, string department, double salary)
    {
        this->employeeID = employeeID;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    double giveBonus(double amount){
        salary += amount;
        cout<< "Bonus added to the salary."<<endl;
        return salary;

    }
    
    bool isManager(){
        if(department == "Management"){
            return true;
        }
        else{
            return false;
        }
    }

    void displayDetails(){
        cout << "Employee ID : "<<employeeID<<endl;
        cout << "Name : "<<name<<endl;
        cout << "Department : "<<department<<endl;
        cout << "Salary : "<<salary<<endl;
    }

};

int main(){
    Employee e1(2122, "Alice Singh", "Management", 65700898);
    Employee e2(1442, "Kinza Daniel", "Product Design", 250000);

    double amount;

    cout << "Initial Employee Details:" << endl;
    cout << endl;
    e1.displayDetails();
    cout << endl;
    e2.displayDetails();
    cout << endl;

    cout << "----Bonus----" << endl;
    cout << "Enter the amount of bonus: ";
    cin >> amount;
    e1.giveBonus(amount);
    cout << endl;
    e2.giveBonus(amount);
    cout << endl;

    cout << "Checking which employee is a manager:" << endl;
    cout << "Employee 1 is Manager: " << (e1.isManager() ? "Yes" : "No") << endl;
    cout << "Employee 2 is Manager: " << (e2.isManager() ? "Yes" : "No") << endl;

    cout << "Final Employee Details:" << endl;
    e1.displayDetails();
    cout << endl;
    e2.displayDetails();

    return 0;
}
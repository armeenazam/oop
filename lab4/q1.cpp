#include<iostream>
#include<string>
using namespace std;

class Student{
private:    
    int studentID;
    string name;
    int age;
    char grade;

public:
Student()
{
    this->grade = 'N';
}

Student(int studentID , string name , int age , char grade)
{
    this->studentID = studentID ;
    this->name = name;
    this->age = age;
    this->grade = grade;
}

char promoteStudent(){
    if(grade > 'A' && grade < 'F')
    {   grade--;
        return grade;
    }
    else{
        cout<<"Promotion not possible for grade A!!"<<endl;
        return grade;
    }
}

  bool isEligibleForScholarship() {
        return grade == 'A';
    }



void displayDetails(){
    cout<<"Name : "<<name<<endl;
    cout<<"Student ID : "<<studentID<<endl;
    cout<<"Age : "<<age<<endl;
    cout<<"Grade : "<<grade<<endl;
}

};

int main()
{
    Student s1(123, "Armeen", 17, 'A');
    Student s2(321, "Venus", 20, 'D');

    cout << "Before Promotion:" << endl;
    s1.displayDetails();
    cout << endl;
    s2.displayDetails();
    cout << endl;

    s1.promoteStudent();
    s2.promoteStudent();

    cout << "\nAfter Promotion:" << endl;
    s1.displayDetails();
    cout << endl;
    s2.displayDetails();
    cout << endl;

    cout << "Scholarship Eligibility:" << endl;
    cout << "Is Armeen eligible for a scholarship? " << (s1.isEligibleForScholarship() ? "Yes" : "No") << endl;
    cout << "Is Venus eligible for a scholarship? " << (s2.isEligibleForScholarship() ? "Yes" : "No") << endl;

    return 0;

    



    
    


}
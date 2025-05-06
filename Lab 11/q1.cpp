#include<iostream>
#include<exception>
#include<string>

using namespace std;

class InvalidValueException : public exception {
private:
    int age;
public:
    InvalidValueException(int age) : age(age) {}

    const char* what() const noexcept override {
        return "Invalid age value! Age must be between 0 and 120.";
    }

    void validateAge() const {
        if (age < 0 || age > 120) {
            throw InvalidValueException(age); // Avoid throwing *this
        }
    }

    int getAge() const {
        return age;
    }
};

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try {
        InvalidValueException ageException(age);
        ageException.validateAge();
        cout << "Your age is: " << age << endl;
    }
    catch (const InvalidValueException& ageException) {
        cout << "Exception: " << ageException.what() << endl;
        
    }
}

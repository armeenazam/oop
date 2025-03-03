#include<iostream>
#include<string>
using namespace std;

class ValidateString {
private:
    string userString;
public:
    ValidateString(string s) : userString(s) {}

// This function is marked as 'const' to indicate that it will not modify
// any member variables of the class. This ensures the function can be safely
// called on constant objects and provides guarantees about the immutability
// of the object during its execution.
   
bool isValid() const {
        for (char c : userString) {
            if (!( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ValidateString s1("OOP");
    ValidateString s2("lab");
    ValidateString s3("14vb:;g@drt");

    cout << "Is 'OOP' valid? " << (s1.isValid() ? "Yes" : "No") << endl;
    cout << "Is 'lab' valid? " << (s2.isValid() ? "Yes" : "No") << endl;
    cout << "Is '14vb:;g@drt' valid? " << (s3.isValid() ? "Yes" : "No") << endl;

    return 0;
}

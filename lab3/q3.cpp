#include <iostream>
using namespace std;

class SerialNumber {
private:
    static int count;
    int serial;
public:
    SerialNumber() {
        serial = ++count;
    }
    void showSerial() const {
        cout << "I am object number " << serial << endl;
    }
};

int SerialNumber::count = 0;

int main() {
    SerialNumber obj1, obj2, obj3;
    obj1.showSerial();
    obj2.showSerial();
    obj3.showSerial();
    return 0;
}

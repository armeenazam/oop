#include <iostream>
#include <iomanip>

using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int d, float m, char dir) {
      degrees = d;
      minutes = m;
      direction = dir;
    }

    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;
    }

    void display() const {
        cout << fixed << setprecision(1);
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle a1(149, 34.8, 'W');
    cout << "Initialized Angle: ";
    a1.display();

    while (true) {
        Angle a2(0, 0.0, 'N');  
        cout << "\nEnter a new angle:\n";
        a2.getAngle();
        cout << "You entered: ";
        a2.display();
    }
    return 0;
}

#include<iostream>
#include <conio.h>
using namespace std;

class Tollbooth{
private :
   unsigned int totalCars;
    double totalCash;
public:
    Tollbooth()
    {
        totalCars = 0;
        totalCash = 0;
    }
    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }
    void nopayCar() {
        totalCars++;
    }
     void display() const {
        cout << "Total cars: " << totalCars << endl;
        cout << "Total cash collected: $" << totalCash << endl;
    }
};

int main()
{
    Tollbooth tb;
    char ch;
    cout << "Please enter: \n 'p' for paying car \n 'n' for non-paying car \n Esc to exit " << endl;
    while (true)
    {
        ch = _getch();
        
        if(ch == 27 )
            break;
        else if(ch=='p'|| ch=='P')
        {
            tb.payingCar();
            cout << "Paying car added." << endl;
        }
        else if(ch=='n'|| ch=='N')
        {
            tb.nopayCar();
            cout << "Non-paying car added." << endl;
        }
    }
    cout << "\n------Final Tally------\n";
    tb.display();

    return 0;
}

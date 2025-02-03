#include<iostream>
#include <iomanip>
using namespace std;

class Time {
private :
    int hours;
    int minutes;
    int seconds;

public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m, int s)  {
          hours = h;
        minutes = m;
        seconds = s;

    }

    void setTime(int hrs , int min ,int sec)
    {
        hours = hrs;
        minutes = min;
        seconds = sec;

    }
     int getHrs()
     {
        return hours;
     }
     int getMin()
     {
        return minutes;
     }
     int getSec()
     {
        return seconds;
     }
    
    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) << seconds << endl;
    }
    void addTime(const Time& t1, const Time& t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + (seconds / 60);
        hours = t1.hours + t2.hours + (minutes / 60);

        seconds %= 60;
        minutes %= 60;
        hours %= 24; 
    }
};
int main() {
    Time t1 , t2;

    cout<<"Please enter time in seconds , minutes , and hours: "<<endl;
    int hrs1 ,hrs2 , min1 ,min2 ,sec1 ,sec2 ;
    cin>>hrs1>>hrs2>>min1>>min2>>sec1>>sec2;
    t1.setTime(hrs1 , min1 , sec1);
    t2.setTime(hrs2 , min2 , sec2);

    Time t3; 

    t3.addTime(t1, t2);
    
    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();
    cout << "Summed Time: "; t3.display();
    return 0;
}

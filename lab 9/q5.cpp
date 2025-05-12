#include <iostream>
using namespace std;
class Activity {
public:
    virtual double calculateCaloriesBurned() = 0; 
    virtual ~Activity() {} 
};
class Running : public Activity {
private:
    double distance; // in kilometers
    double time;     // in minutes
public:
    Running(double d, double t) : distance(d), time(t) {}
    double calculateCaloriesBurned() override {
        // Assuming 1 km burns 50 calories
        return (distance * 50); 
    }
};
class Cycling : public Activity {
private:
    double speed; // in km/h
    double time;  // in hours
public:
    Cycling(double s, double t) : speed(s), time(t) {}
    double calculateCaloriesBurned() override {
        // Assuming 1 hour of cycling at 20 km/h burns 300 calories
        return (speed * time * 15); 
    }
};
int main(){
    

    Running run(5, 30); // 5 km in 30 minutes
    Cycling cycle(20, 1); // 20 km/h for 1 hour
    return 0;
}

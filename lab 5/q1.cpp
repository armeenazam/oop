#include<iostream>
#include<string>
using namespace std;

class Square{
private:
    float sideLength;
    float area;
    static float allareas;
public:
    Square(){
        sideLength = 0.0;
        area = 0.0; 
    }
    Square(float sideLength){
        setSideLength(sideLength);
    }
    void setSideLength(float sl){
        this->sideLength= sl;
    }
    void setArea(float a){
        area = a;
    }
    static float getAllareas(){
        return allareas;
    }

    float getSideLength(){
        return sideLength;
    }
    float getArea(){
        return area;
    }
    void calculateArea(){
        area = sideLength * sideLength;
        allareas += area;
    }

};
float Square :: allareas = 0.0; 

int main(){
    
    Square sq1(4.4);
    Square sq2(3.3);
    Square sq3(2.2);
    cout<< sq1.getSideLength()<< endl;
   
   sq1.calculateArea();
   cout << "Square 1 - Side Length: " << sq1.getSideLength() << ", Area: " << sq1.getArea() << endl;
   cout << "Total Area of All Squares: " << Square::getAllareas() << endl;

   sq2.calculateArea();
   cout << "Square 2 - Side Length: " << sq2.getSideLength() << ", Area: " << sq2.getArea() << endl;
   cout << "Total Area of All Squares: " << Square::getAllareas() << endl;

   sq3.calculateArea();
   cout << "Square 3 - Side Length: " << sq3.getSideLength() << ", Area: " << sq3.getArea() << endl;
   cout << "Total Area of All Squares: " << Square::getAllareas() << endl;

}

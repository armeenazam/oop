#include<iostream>
#include <exception>
#include <typeinfo>
#include<string>
#include<cmath>
using namespace std;
class negativenumberexception:public std::exception{
    public :
    const char*what()const noexcept override{
        return "Negative Number exception occurred";
    }
};
class invalidTypeException:public std::exception{
    public:
    const char*what()const noexcept override{
        return "Invalid Type exception occurred";
    }
};
template<typename T> void sqrtf(T num){
    if (num < 0) {
        throw negativenumberexception();
    } else if (typeid(num) != typeid(int) || typeid(num) != typeid(float)) {
        throw invalidTypeException();
    } else {
        std::cout << "Square root of " << num << " is " <<sqrt(num)<< std::endl;
    }
}
int main(){
    try{
        sqrtf(-4);
   }
    catch(const negativenumberexception& e){
        cout<<e.what()<<endl;
    }
    try{
        sqrtf('h');}
    catch(const invalidTypeException& e){
        cout<<e.what()<<endl;
    }
    catch(const std::exception& e){
        cout<<e.what()<<endl;
    }
    return 0;
    
}
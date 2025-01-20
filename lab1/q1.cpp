#include<iostream>
using namespace std;
int main()
{
    int num,count;
    cout<<"Enter a number :";
    cin>>num;
    for(int i=1 ; i<=num ; i++)
    {
        if(num%i==0)
        count++;

    }
    if(count==2)
    {
        cout<<"Given number is prime ";
    }
    else{
        cout<<"Given number is not prime ";
    }
}
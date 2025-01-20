#include<iostream>
using namespace std;
int main()
{
    int n,target;
    cout<<"Enter the number of elements :";
    cin>>n;
    int array[n];
    int result[2];
    cout<<"Enter the elements :";
    for(int i=0 ; i<n ; i++)
    {
        cin>>array[i];
        
    }
    cout<<"Enter the target integer :";
    cin>>target;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] + array[j] == target) {
                result[0] = i;
                result[1] = j;
            }
        }
    }
    if (result != NULL) {
        cout<<"Indices: ["<<result[0]<<","<<result[1]<<"]"<<endl;
    } else {
        cout<<"No solution found.\n";
    }
}
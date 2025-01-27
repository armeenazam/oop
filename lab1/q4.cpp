#include <iostream>
using namespace std;

int maxArea(int height[], int n) {
    int left = 0, right = n - 1;
    int maxArea = 0;

    while (left < right) {
        int currentArea = min(height[left], height[right]) * (right - left);
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int *height = new int[n];
    cout<<"Enter the elements: ";
    for (int i=0 ; i<n ; i++)
    {
        cin>>height[i];
    }
    int result = maxArea(height, n);
    cout<<"Maximum water a container can store: " <<result<< endl;
    
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    float *arr = new float[n];
    cout << "Enter the numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }
    
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += *(arr + i);
    }
    float avg = sum / n;
    float closest = *arr; 
    for (int i = 1; i < n; ++i) {
        if (fabs(*(arr + i) - avg) < fabs(closest - avg)) {
            closest = *(arr + i);
        }
    }
    cout << "Average: " << avg << endl;
    cout << "Number closest to the average: " << closest << endl;
    delete[] arr;

    return 0;
}

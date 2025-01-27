#include <iostream>
#include <cstring>
using namespace std;
int countVowels(const char *str) {
    int count = 0;
    while (*str) {
        char c = tolower(*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        str++;
    }
    return count;}
int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    char **arr = new char*[n];
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; ++i) {
        arr[i] = new char[100];
        cin >> arr[i];
    }
    cout << "\nStrings in reverse order:" << endl;
    for (int i = n - 1; i >= 0; --i) {
        cout << *(arr + i) << endl;
    }
    char *maxVowelStr = *arr;
    int maxVowelCount = countVowels(*arr);
    for (int i = 1; i < n; ++i) {
        int currentVowelCount = countVowels(*(arr + i));
        if (currentVowelCount > maxVowelCount) {
            maxVowelCount = currentVowelCount;
            maxVowelStr = *(arr + i);
        }
    }
    int totalLength = 0;
    for (int i = 0; i < n; ++i) {
        totalLength += strlen(*(arr + i));
    }
    float avgLength = static_cast<float>(totalLength) / n;
    cout << "\nString with the most vowels: " << maxVowelStr << endl;
    cout << "Average length of strings: " << avgLength << endl;
    for (int i = 0; i < n; ++i) {
        delete[] *(arr + i);
    }
    delete[] arr;
    return 0;}


#include <iostream>
#include<fstream>
#include <exception>
using namespace std;
class fileexception : public std::exception {
    public:
    const char* what()const noexcept override{
        return "File exception occurred";
    };
};
class filenotfoundexception : public fileexception {
    public:
    const char* what()const noexcept override{
        return "File not found exception occurred";
    }
};
class permissiondeniedexception : public fileexception {
    public:
    const char* what()const noexcept override{
        return "Permission denied exception: Access denied";
    }
};
void ReadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw permissiondeniedexception();
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main(){

    string filename;
    cout << "Enter the filename to read: ";
    cin >> filename;
    try {
        ReadFile(filename);
    } catch (const filenotfoundexception& e) {
        cout << "Reading '" << filename << "': " << e.what() << endl;
    } catch (const permissiondeniedexception& e) {
        cout << "Reading '" << filename << "': " << e.what() << endl;
    } catch (const fileexception& e) { 
        cout << "Reading '" << filename << "': " << e.what() << endl;
    }

    return 0;
}
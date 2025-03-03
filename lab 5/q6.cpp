#include<iostream>
#include<string>
using namespace std;

class GraphicsRenderingEngine{
private:
    string name;
    int model;
public:
    GraphicsRenderingEngine(string n, int m){
        name = n;
        model = m;
    }   
    void display(){
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
    }
};

class InputHandler{
private:
    string type;
    int buttons;
public:
    InputHandler(string t, int b){
        type = t;
        buttons = b;
    }
    void display(){
        cout << "Type: " << type << endl;
        cout << "Buttons: " << buttons << endl;
    }    
};

class PhysicsEngine{
private:
    string type;
    int version;
public:
    PhysicsEngine(string t, int v){
        type = t;
        version = v;
    }
    void display(){
        cout << "Type: " << type << endl;
        cout << "Version: " << version << endl;
    }    
};
class GameEngine{
private:
    GraphicsRenderingEngine gre;
    InputHandler ih;
    PhysicsEngine pe;
public:
   GameEngine(string n, int m, string t, int b, string ty, int v):
        gre(n, m), ih(t, b), pe(ty, v){}
        
    void display(){
        cout << "Game Engine Details: \n";
        gre.display();
        ih.display();
        pe.display();
        cout << endl;
    }
};

int main(){
    GameEngine ge("Unity", 2021, "Joystick", 5, "Box2D", 2);
    ge.display();
    return 0;
}
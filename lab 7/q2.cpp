#include <iostream>
#include <cmath>
using namespace std;

// Base Shape class
class Shape {
protected:
    string color;
    int borderThickness;
public:
    Shape(string col = "black", int border = 1) : color(col), borderThickness(border) {}
    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    virtual ~Shape() {}
};

// Circle class
class Circle : public Shape {
private:
    double radius;
    int centerX, centerY;
public:
    Circle(double r, int x, int y, string col = "black", int border = 1) 
        : Shape(col, border), radius(r), centerX(x), centerY(y) {}
    void draw() const override {
        cout << "Drawing Circle at (" << centerX << ", " << centerY << ") with radius " << radius << "\n";
    }
    double calculateArea() const override { return M_PI * radius * radius; }
    double calculatePerimeter() const override { return 2 * M_PI * radius; }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double width, height;
    pair<int, int> topLeft;
public:
    Rectangle(double w, double h, int x, int y, string col = "black", int border = 1)
        : Shape(col, border), width(w), height(h), topLeft({x, y}) {}
    void draw() const override {
        cout << "Drawing Rectangle at (" << topLeft.first << ", " << topLeft.second << ") with width " << width << " and height " << height << "\n";
    }
    double calculateArea() const override { return width * height; }
    double calculatePerimeter() const override { return 2 * (width + height); }
};

// Triangle class
class Triangle : public Shape {
private:
    pair<int, int> v1, v2, v3;
public:
    Triangle(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, string col = "black", int border = 1)
        : Shape(col, border), v1(p1), v2(p2), v3(p3) {}
    void draw() const override {
        cout << "Drawing Triangle with vertices at (" << v1.first << ", " << v1.second << "), (" << v2.first << ", " << v2.second << "), (" << v3.first << ", " << v3.second << ")\n";
    }
    double calculateArea() const override {
        return abs((v1.first * (v2.second - v3.second) + v2.first * (v3.second - v1.second) + v3.first * (v1.second - v2.second)) / 2.0);
    }
    double calculatePerimeter() const override {
        double a = sqrt(pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2));
        double b = sqrt(pow(v2.first - v3.first, 2) + pow(v2.second - v3.second, 2));
        double c = sqrt(pow(v3.first - v1.first, 2) + pow(v3.second - v1.second, 2));
        return a + b + c;
    }
};

// Polygon class
class Polygon : public Shape {
private:
    pair<int, int>* vertices;
    int vertexCount;
public:
    Polygon(pair<int, int>* v, int count, string col = "black", int border = 1) : Shape(col, border), vertexCount(count) {
        vertices = new pair<int, int>[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            vertices[i] = v[i];
        }
    }
    ~Polygon() {
        delete[] vertices;
    }
    void draw() const override {
        cout << "Drawing Polygon with " << vertexCount << " vertices.\n";
    }
    double calculateArea() const override {
        double area = 0;
        for (int i = 0; i < vertexCount; i++) {
            int j = (i + 1) % vertexCount;
            area += (vertices[i].first * vertices[j].second - vertices[j].first * vertices[i].second);
        }
        return abs(area / 2.0);
    }
    double calculatePerimeter() const override {
        double perimeter = 0;
        for (int i = 0; i < vertexCount; i++) {
            int j = (i + 1) % vertexCount;
            perimeter += sqrt(pow(vertices[i].first - vertices[j].first, 2) + pow(vertices[i].second - vertices[j].second, 2));
        }
        return perimeter;
    }
};

// Main function
int main() {
    Circle c(5, 10, 10, "red", 2);
    Rectangle r(4, 6, 2, 3, "blue", 1);
    Triangle t({0, 0}, {4, 0}, {2, 3}, "green", 1);
    pair<int, int> polygonVertices[] = {{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    Polygon p(polygonVertices, 4, "purple", 1);
    
    Shape* shapes[] = {&c, &r, &t, &p};
    int shapeCount = 4;
    
    for (int i = 0; i < shapeCount; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << "\n";
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << "\n\n";
    }
    return 0;
}

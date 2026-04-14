#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float radius) {
        this->radius = radius;
    }

    float area() {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float lenght, float width) {
        this->length = lenght;
        this->width = width;
    }

    float area() {
        return length * width;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);

    cout << "Area of circle:";
    cout << c.area();
    cout << "\nArea of rectangle:";
    cout << r.area();


    return 0;
}
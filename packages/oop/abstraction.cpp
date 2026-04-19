#include <iostream>
#include <string>
using namespace std;

// Abstract base class as there is a
// pure virtual method
class Shape{
    protected:
        string color;

    public:
        Shape(string color) : color(color){}

        // Abstract or Pure virtual method
        virtual double area() = 0;

        // Concrete method
        string getColor(){
            return color;
        }

        virtual ~Shape() {}
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double length, width;

    public:
        Rectangle(string color, double length, double width) : Shape(color){
            this->length = length;
            this->width = width;
        }
        double area() override {
            return length * width;
        }
};

int main() {
    Shape* s = new Rectangle("Yellow", 2, 4);

    cout<<"Rectangle color is "<<s->getColor()<<" and area is : "<<s->area()<<endl;
    return 0;
}
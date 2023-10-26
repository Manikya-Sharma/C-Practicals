#include <iostream>

using namespace std;

class Shape
{
protected:
    int sides;

public:
    virtual void area(){
        cout << "Ambiguity" << endl;
    };
};

class Rectangle : public Shape
{
protected:
    int a;
    int b;

public:
    Rectangle(int a, int b) : a(a), b(b) {}
    void area() { cout << "Area is " << a * b << endl; }
};

class Square : public Rectangle
{
public:
    Square(int x) : Rectangle(x, x) {}
};

int main() {

    Square sq(5);
    Shape *sq_ptr = &sq;

    sq_ptr->area();

    return 0;
}
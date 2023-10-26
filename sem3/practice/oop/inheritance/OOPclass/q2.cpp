#include <iostream>
using namespace std;

class Base
{
public:
    virtual void display() { cout << "Base func" << endl; }
};

class Derived : public Base
{
public:
    void display() { cout << "Derived function" << endl; }
};

class Derived2 : public Derived
{
public:
    void display() { cout << "Derived 2" << endl; }
};

int main()
{
    Derived2 d;
    Base *b = &d;
    b->display();
    return 0;
}
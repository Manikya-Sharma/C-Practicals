#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base contructor called" << endl; }
    ~Base() { cout << "Base destructor called" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived contructor called" << endl; }

    ~Derived() { cout << "Derived destructor called" << endl; }
};

int main() { Derived d; }

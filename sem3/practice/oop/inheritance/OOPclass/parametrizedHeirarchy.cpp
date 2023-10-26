#include <iostream>
using namespace std;

class A
{
protected:
    int x;

public:
    A() { cout << "Default constructor" << endl; }
    A(int a) { x = a; }
};

class B : public A
{
protected:
    int y;

public:
    B(int a, int b)
    {
        A(); // you cant call parametrized here
        y = b;
    }
};

class C : public B
{
protected:
    int z;

public:
    C(int a, int b, int c) : B(a, b) { z = c; }

    void displayAll()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }
};

int main()
{

    C c(5, 6, 7);
    c.displayAll();

    return 0;
}
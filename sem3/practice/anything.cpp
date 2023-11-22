/* #include <iostream>
using namespace std;

class X {
  public:
    int a;
    void f(int b) { cout << "Value of b is " << b << endl; }
};

int main()
{
    int X ::*ptiptr = &X::a;
    void (X::*ptfptr)(int) = &X::f;
    X xobject;
    xobject.*ptiptr = 10;
    cout << "Value of a is " << xobject.a << endl;
    (xobject.*ptfptr)(20);
} */

#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A(int x) : x(x) {}
    void printX() { cout << "x = " << x << endl; }
};

class B : public A
{
    // x is inherited but not accessible
public:
    B(int x) : A(x) {}
};

class C
{
    void sayHello() { cout << "hello" << endl; }
};

int main()
{
    B b(5);
    A a(5);
    C c;
    cout << "Size of A = " << sizeof(a) << endl;
    cout << "Size of B = " << sizeof(b) << endl;
    cout << "Size of C = " << sizeof(c) << endl;
    b.printX();
    return 0;
}
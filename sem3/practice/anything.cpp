#include <iostream>
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
}
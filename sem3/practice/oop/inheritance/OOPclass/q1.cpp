#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    int a;
    A(int a1)
    {
        a = a1;
        cout << "A's constructor " << a << endl;
    }
};

class B : virtual public A
{
public:
    B() {}
    B(int a1) : A(a1)
    {
        a = 30 + a1;
        cout << "B's constructor " << a << endl;
    }
    void b_print() { cout << a << endl; }
};

class C : public virtual A
{
public:
    C() {}
    C(int a1) : A(a1)
    {
        A();
        a = a1 + 10;
        cout << "C's contrutor " << a << endl;
    }
};

class D : public B, public C
{
public:
    D(int a1) : C(a1), B(a1)
    {
        C();
        B();
        a = a1;
        cout << "D's constructor " << a << endl;
    }
};

int main()
{
    D d(90);
    d.b_print();
    return 0;
}
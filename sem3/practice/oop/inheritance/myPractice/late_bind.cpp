#include <iostream>
using namespace std;

class A
{
public:
    virtual void func() { cout << "Hi from base class" << endl; }
};

class B : public A
{
public:
    void func() { cout << "Hi from B class" << endl; }
};

class C : public B
{
public:
    void func() { cout << "Hi from C class" << endl; }
};

int main()
{
    B *ptr = new C();

    ptr->func();

    delete ptr;

    return 0;
}

#include <iostream>
using namespace std;

class A
{
public:
    int x;

public:
    void printx() { cout << x << endl; }
};

class B : virtual public A
{
public:
    void printx() { cout << x << endl; }
};


class C : virtual public A
{
public:
    void printx() { cout << x << endl; }
};

class D : public B, public C
{
public:
    void printx() { cout << x << endl; }
};

int main() {}
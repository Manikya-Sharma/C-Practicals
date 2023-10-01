#include <iostream>
using namespace std;

class B;

class A {
    int a;
    friend void friend_display(A, B);
};

class B {
    int b;
    friend void friend_display(A, B);
};

void display(A objA, B objB)
{
    cout << "Hello" << endl;
}

void friend_display(A objA, B objB)
{
    cout << "a -> " << objA.a << endl;
    cout << "b -> " << objB.b << endl;
    display(objA, objB);
}

int main() {
    A a;
    B b;
    display(a, b);
    return 0;
}

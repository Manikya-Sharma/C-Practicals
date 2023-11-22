#include <iostream>
using namespace std;

template <class T>
void sum(T a, T b)
{
    cout << (a + b) << endl;
}

template <>
void sum(int a, int b)
{
    cout << (a + b) << "(INT)" << endl;
}

template <class T>
class A
{
    T element;

public:
    A(T arg) { element = arg; }
};

template <>
class A<char>
{
    char element;

public:
    A(char arg) { element = arg; }
    void increment() { cout << (element + 1) << endl; }
};

int main()
{
    sum(1, 2);
    sum(1.2, 3.4);
    A<int> a(1);
    A<char> b('b');
    b.increment();
    return 0;
}
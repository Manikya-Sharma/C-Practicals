#include <iostream>
using namespace std;

template <class T>
void print(T obj)
{
    cout << "Object: " << obj << endl;
}

template <>
void print(char obj)
{
    cout << "Char :" << obj << endl;
}

int main()
{
    print(55);
    print('a');

    return 0;
}
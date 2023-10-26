#include<iostream>
using namespace std;

template<class T>
class A
{
    T a;
    T b;
public:
    A(T first, T second) { a = first; b = second; }
    T Getmax(T c);
};

template <class T>
T A<T>::Getmax(T c)
{
    T res;
    res = a > b ? a : b;
    cout << res << endl;
    return res;
}

int main()
{
    A<int> obj1(6, 7);
    obj1.Getmax(7);
    return 0;
}

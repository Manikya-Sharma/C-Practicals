#include <iostream>
using namespace std;

class MyNum2;

class MyNum1
{
    int data;

public:
    MyNum1(int x) { data = x; }
    void operator+(MyNum2);
};

class MyNum2
{
    int data;
    friend void MyNum1::operator+(MyNum2);

public:
    MyNum2(int x) { data = x; }
};

void MyNum1::operator+(MyNum2 num)
{
    cout << "SUM(" << data + num.data << ")\n";
}

int main()
{
    MyNum1 m(5);
    MyNum2 n(7);
    m + n;
    return 0;
}
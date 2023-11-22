#include <iostream>
using namespace std;

class MyNum
{
    int x;

public:
    MyNum(int a) : x(a) {}
    friend ostream &operator<<(ostream &os, MyNum mn);
    MyNum operator=(int num)
    {
        MyNum m(num);
        return m;
    }
};

ostream &operator<<(ostream &os, MyNum mn)
{
    os << mn.x << "(My Num)";
    return os;
}

int main()
{
    // MyNum m(5);
    int a = 5;
    MyNum m = a;

    // between objects: dynamic_cast<>()

    return 0;
}
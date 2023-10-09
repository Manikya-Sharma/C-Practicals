#include <iostream>
using namespace std;

class CustomNumber
{
    int value;

public:
    CustomNumber() {}
    CustomNumber(int value) : value(value) {}

    friend ostream &operator<<(ostream &os, CustomNumber cn);
    friend istream &operator>>(istream &is, CustomNumber cn);
    CustomNumber operator+(CustomNumber cn)
    {
        CustomNumber c2;
        c2.value = value + cn.value;
        return c2;
    }
    CustomNumber operator=(CustomNumber cn)
    {
        value = cn.value;
        return cn;
    }
    int operator%(CustomNumber cn) { return value % cn.value; }
};

ostream &operator<<(ostream &os, CustomNumber cn)
{
    os << cn.value << " (custom number)";
    return os;
}

istream &operator>>(istream &is, CustomNumber cn)
{
    is >> cn.value;
    return is;
}

int main()
{
    CustomNumber cn1(5);
    CustomNumber cn2(7);
    CustomNumber cn3(18);
    cout << cn1 << endl << cn2 << endl << cn3 << endl;
    cn3 = cn1 = cn2;
    cout << endl;
    cout << cn1 << endl << cn2 << endl << cn3 << endl;
    return 0;
}
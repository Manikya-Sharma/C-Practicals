#include <iostream>
using namespace std;

class CustomNumber
{
    int value;

public:
    CustomNumber() : value(0) {}
    CustomNumber(int value) : value(value) {}

    ostream &operator<<(ostream &os)
    {
        os << value << " (custom number)";
        return os;
    }
    istream &operator>>(istream &is)
    {
        is >> value;
        return is;
    }
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

int main()
{
    CustomNumber cn1(5);
    CustomNumber cn2;
    cout << "Enter number 2:";
    cn2 >> cin;

    cn1 << cout;
    cout << endl;

    cn2 << cout;
    cout << endl;

    cout << "number1 + number2: ";
    (cn1 + cn2) << cout;
    cout << endl;

    cout << "number1 % number2: ";
    cout << (cn1 % cn2);
    cout << endl;

    cn1 = cn2;
    cout << "After assignment:-" << endl;
    cn1 << cout;
    cout << endl;
    cn2 << cout;
    cout << endl;

    return 0;
}
#include <exception>
#include <iostream>
#include <string.h>
using namespace std;

class TypeException/*  : exception */
{
public:
    char *what()
    {
        char *err = new char[14];
        strcpy(err, "Invalid types");
        return err;
    }
};

template <class T, class U>
class Operator
{
    T num1;
    U num2;

public:
    Operator(T a, U b) : num1(a), num2(b) {}
    T add()
    {
        T sum;
        try
        {
            if (typeid(num1) != typeid(num2))
            {
                throw TypeException();
            }
            sum = (num1 + num2);
        } catch (exception e)
        {
            cout << e.what() << endl;
        }
        return sum;
    }
};

int main()
{
    Operator<int, float> op(1, 3);

    cout << op.add() << endl;

    return 0;
}
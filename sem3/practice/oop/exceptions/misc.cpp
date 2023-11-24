#include <iostream>
#include <string.h>
using namespace std;

class OverweightExcpetion : public exception
{
    string s;

public:
    OverweightExcpetion(string s) : s(s) {}
    string what() { return s; }
};

class Measure
{
public:
    static void weigh(int inp)
    {
        try
        {
            if (inp > 1000)
            {
                throw OverweightExcpetion("Too much weight!");
            } else
            {
                cout << "The weight is " << inp << endl;
            }
        } catch (OverweightExcpetion e)
        {
            cout << e.what() << endl;
        }
    }
};

int main()
{
    int w = 50000;
    Measure::weigh(w);
    return 0;
}
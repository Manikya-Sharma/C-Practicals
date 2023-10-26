#include <exception>
#include <iostream>
using namespace std;

class DummyException : public exception
{
public:
    const char *what() { return "A dummy exception occured"; }
};

class TryingDivisionByZeroException : public exception
{
public:
    const char *what() { return "You are trying to divide by zero"; }
};

int main()
{
    /* cout << "Enter age: ";
    int age;
    cin >> age;

    try
    {
        if (age < 18)
        {
            throw DummyException();
        }
        cout << "You can drive" << endl;
    } catch (int a)
    {
        cout << "You cannot drive" << endl;
    } catch (DummyException d) {
        cout << d.what() << endl;
    } */

    int a, b;
    cout << "Enter a and b (space separated)" << endl;
    cin >> a >> b;
    try
    {
        if (b == 0)
        {
            throw TryingDivisionByZeroException();
        }
        cout << "a/b = " << a / b << endl;
    } catch (TryingDivisionByZeroException e)
    {
        cout << e.what() << endl;
        cout << "Stopping execution" << endl;
    }
    catch (...) {
        cout << "Some error occured" << endl;
    }
    return 0;
}
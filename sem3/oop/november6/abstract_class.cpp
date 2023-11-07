#include <iostream>
using namespace std;

class AbstractClass
{
public:
    virtual void showData() = 0;
};

class CustomClass1 : public AbstractClass
{
    int data;

public:
    CustomClass1(int data) : data(data) {}
    void showData() { cout << "Data = " << data << endl; }
};

class CustomClass2 : AbstractClass {};

int main()
{
    /*
    We are not allowed to instantiate an abstract class
    Therefore, the following statement will give an error
     */

    // AbstractClass ab;

    // since CustomClass1 implements pure virtual function, it is not abstract
    CustomClass1 cls(5);
    cls.showData();
    // CustomClass2 does not implement a pure virtual function. Therefore it is
    // abstract therefore, following line will give an error
    /* CustomClass2 cls2; */
    return 0;
}
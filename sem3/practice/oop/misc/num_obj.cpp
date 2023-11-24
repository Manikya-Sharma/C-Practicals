#include <iostream>
using namespace std;

class BaseObject
{
public:
    static int num_objects;
    static void showObjects()
    {
        cout << "NUMBER OF OBJECTS:" << num_objects << endl;
    }
};

class Object : public BaseObject
{
public:
    Object() { BaseObject::num_objects++; }
    ~Object() { BaseObject::num_objects--; }
};

int BaseObject::num_objects = 0;

int main()
{
    BaseObject::showObjects();
    Object a;
    BaseObject::showObjects();
    {
        Object b;
        BaseObject::showObjects();
        {
            Object c;
            BaseObject::showObjects();
        }
        BaseObject::showObjects();
    }
    BaseObject::showObjects();
    return 0;
}
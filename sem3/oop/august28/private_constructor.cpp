#include <iostream>
#define BASE_PRICE 7000

using namespace std;

class Mobile
{
    int android_version;
    float price;
    char model;

    Mobile()
    {
        cout << "\n**** Private default constructor called ****\n"
             << endl;
    }

    Mobile(int ver, char model)
    {
        cout << "**** Private constructor called ****" << endl;
        android_version = ver;
        this->model = model;
        price = BASE_PRICE + (model - 'a') * 600 + android_version * 300;
    }

public:
    static Mobile newMobile()
    {
        Mobile mb;
        mb.android_version = 15;
        mb.model = 'd';
        mb.price = 1500;
        return mb;
    }
    static Mobile newMobile(int ver, char model)
    {
        Mobile mb(ver, model);
        return mb;
    }
    void display()
    {
        cout << "Model: " << model << endl;
        cout << "Android version: " << android_version << endl;
        cout << "With price: " << price << "(Rs)" << endl;
    }
};

int main()
{
    Mobile mb = Mobile::newMobile(13, 'c');
    Mobile mb2 = Mobile::newMobile();
    mb.display();
    mb2.display();
    return 0;
}

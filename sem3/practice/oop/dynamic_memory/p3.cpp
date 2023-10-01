#include<iostream>
using namespace std;

class student {
    private:
    int age;
    public:
    student(): age(12)
    {}
    void getAge() { cout << "Age: " << age << endl;}
};



int main()
{
    student *ptr = new student();
    ptr->getAge();
    delete ptr;
    return 0;
}
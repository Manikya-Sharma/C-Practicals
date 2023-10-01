#include <iostream>
#include <string.h>
using namespace std;

class Student {
    string name;

  public:
    Student(string newName) { this->name = newName; }
    void greet() { cout << "Hii, I am " << name << endl; }
    ~Student() { cout << "Bye bye --from " << name << " :(" << endl; }
};

int main()
{
    Student s1("Jasnoor");
    s1.greet();
    {
        Student s2("Manikya");
        s2.greet();
    }
    return 0;
}

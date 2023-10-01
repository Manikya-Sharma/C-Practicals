#include <iostream>
using namespace std;

class student {
  string name;
  int age;

public:
  student() { cout << "contructor"; }
  student(string name, int age) {
    this->name = name;
    this->age = age;
  }
  void display() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }
  void *operator new(size_t size) {
    cout << "Overloaded new operator" << endl;
    void *p = malloc(size);
    return p;
  }
  void operator delete(void *p) {
    cout << "Overloaded delete" << endl;
    free(p);
  }
};

int main() {
  student *p = new student("ABC", 14);
  p->display();
  delete p;
  return 0;
}
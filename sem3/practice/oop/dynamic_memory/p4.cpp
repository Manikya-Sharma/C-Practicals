#include <iostream>
#include <new>
using namespace std;

class Complex {
  float a;
  float b;
  friend ostream &operator<<(ostream &os, Complex cmp);

public:
  Complex operator+(Complex op) {
    Complex temp;
    temp.a = a + op.a;
    temp.b = b + op.b;
    return temp;
  }
  Complex operator++() {
    cout << "Without dummy" << endl;
    a++;
    b++;
    return *this;
  }

  Complex operator++(int x) {
    cout << "With dummy" << endl;
    a++;
    b++;
    return *this;
  }

  Complex() : a(0), b(0) {}
  Complex(int a, int b) : a(a), b(b) {}

  void *operator new(size_t size) {
    cout << "NEW!" << endl;
    void *temp = ::operator new(size);
    return temp;
  }
  void operator delete(void *ptr) {
    cout << "DELETED!" << endl;
    free(ptr);
  }
};

ostream &operator<<(ostream &os, Complex cmp) {
  os << cmp.a << " + i" << cmp.b;
  return os;
}

int main() {
  Complex cmp1(3, 2);
  cout << cmp1 << endl;
  Complex cmp2(5, 7);
  cout << cmp2 << endl;
  cout << "Sum: " << (cmp1 + cmp2) << endl;
  cmp1++;
  cout << cmp1 << endl;
  ++cmp2;
  cout << cmp2 << endl;

  Complex *newCmp = new Complex;
  cout << (*newCmp) << endl;
  delete newCmp;

  return 0;
}
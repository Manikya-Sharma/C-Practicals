#include <iostream>
using namespace std;

class Complex
{

    float real;
    float imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(float a, float b) : real(a), imag(b){};

    void display()
    {
        cout << real << (imag < 0 ? '-' : '+') << "i"
             << (imag < 0 ? -imag : imag) << endl;
    }

    friend Complex operator-(Complex, Complex);
    friend Complex operator-(Complex);
    friend void operator++(Complex &, int dummy);
    friend void operator++(Complex &);
    friend Complex operator/(Complex, Complex);
};

Complex operator-(Complex cmp1, Complex cmp2)
{
    Complex result(cmp1.real - cmp2.real, cmp1.imag - cmp2.imag);
    return result;
}

Complex operator-(Complex cmp)
{
    Complex result(-cmp.real, -cmp.imag);
    return result;
}

void operator++(Complex &cmp, int dummy)
{
    // post increment
    cmp.real++;
    cmp.imag++;
}

void operator++(Complex &cmp)
{
    // pre increment
    cmp.real++;
    cmp.imag++;
}

Complex operator/(Complex cmp1, Complex cmp2)
{
    float magnitude = cmp2.real * cmp2.real + cmp2.imag * cmp2.imag;
    float newReal = (cmp1.real * cmp2.real + cmp1.imag * cmp2.imag) / magnitude;
    float newImag = (cmp1.imag * cmp2.real - cmp1.real * cmp2.imag) / magnitude;
    return Complex(newReal, newImag);
}

int main()
{
    Complex a(5, 7);
    Complex b(8, 9);

    cout << "Complex1: ";
    a.display();
    cout << "Complex2: ";
    b.display();

    cout << "Complex2 - Complex1: ";
    (a - b).display();
    cout << "-Complex1: ";
    (-a).display();

    cout << "Complex1++: ";
    a++;
    a.display();

    cout << "++Complex2: ";
    ++b;
    b.display();

    cout << "Complex1/Complex2: ";
    (a / b).display();

    return 0;
}
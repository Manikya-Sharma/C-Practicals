#include <iostream>
using namespace std;

class a
{
private:
    int x;

public:
    a() { cout << "Default called\n"; }
    a(int x1) { cout << "Parametrized called" << (x = x1) << endl; }
    a(const a &t2, int i)
    {
        cout << "copy constructor" << i << endl;
        x = t2.x;
    }
    a ret_a(a t3)
    {
        a temp(t3, 3);
        temp.x = temp.x + 20;
        return temp;
    }
    int getX()
    {
        return x;
    }
};

int main()
{
    a t1(7);
    a t2(t1, 1);
    cout << "t1.x = " << t1.getX() << "\n";
    cout << "t2.x = " << t2.getX() << "\n";
    a one1;
    a t4(30);
    a result_new(one1.ret_a(t4), 2);
    cout << "Final result " << result_new.getX() << endl;
    return 0;
}
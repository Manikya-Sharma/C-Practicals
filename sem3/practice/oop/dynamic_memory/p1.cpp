#include <iostream>
using namespace std;

int main()
{
    int *p;
    float *fp;
    p = new int;
    fp = new float;
    *p = 45;
    *fp = 45.4;
    cout << *p << endl;
    cout << *fp<< endl;
    delete p;
    delete fp;
    return 0;
}
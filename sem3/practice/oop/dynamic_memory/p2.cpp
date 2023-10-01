#include <iostream>
using namespace std;

int main() {
    cout << "Enter number: ";
    int num;
    cin >> num;
    float *ptr;
    ptr = new float[num]; // array
    for (int i=0; i<num; i++)
    {
        cout << "Student " << (i+1) << ": " << *(ptr+i) << endl;
    }
    delete [] ptr; // delete array
    return 0;
}
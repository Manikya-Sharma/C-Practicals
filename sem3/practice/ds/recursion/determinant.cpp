#include <iostream>
using namespace std;

class Matrix {
    int order;
    int *arr;

  public:
    Matrix(int order) : order(order) { arr = new int[order * order]; }
    void setValues()
    {
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                int elem;
                cout << "Enter element (" << i << "," << j << "): ";
                cin >> elem;
                arr[order * i + j] = elem;
            }
        }
    }
    ~Matrix() { delete[] arr; }
    void printMatrix()
    {
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                cout << arr[order * i + j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix mt(3);
    mt.setValues();
    mt.printMatrix();
}
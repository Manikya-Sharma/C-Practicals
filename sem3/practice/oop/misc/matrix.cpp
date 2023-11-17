#include <iostream>
using namespace std;

class Matrix
{
    int rows;
    int cols;
    int **items;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        items = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            items[i] = new int[cols];
        }
    }

    void setItems(int **arr)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                items[i][j] = arr[i][j];
            }
        }
    }

    void takeInput()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter the value for (" << (i + 1) << (j + 1) << "):";
                cin >> items[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << items[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose()
    {
        int i = 0, j = 0, k = 0;
        while (i < rows && j < cols)
        {
            int temp = items[i][j];
            items[i][j] = items[j][i];
            items[j][i] = temp;
            i++;
            if (i == cols)
            {
                j = k + 1;
                i = k + 1;
                k++;
            }
        }
    }

    int determinant()
    {
        if (rows == 0 && cols == 0)
        {
            return 0;
        }
        if (rows == 1 && cols == 1)
        {
            return items[0][0];
        }
        int avoid_x = 0, avoid_y = 0;
        int sum = 0, neg = 1;
        while (avoid_x < rows && avoid_y < cols)
        {
            Matrix temp(rows - 1, cols - 1);
            int **newArr = new int *[rows - 1];
            for (int i = 0; i < cols - 1; i++)
            {
                newArr[i] = new int[cols - 1];
            }

            int i = 0, flag_x = 0;
            while (i < rows)
            {
                int flag_y = 0, j = 0;
                if (i == avoid_x)
                {
                    flag_x = 1;
                    i++;
                    continue;
                }
                while (j < cols)
                {
                    if (j == avoid_y)
                    {
                        flag_y = 1;
                        j++;
                        continue;
                    }
                    newArr[i - flag_x][j - flag_y] = items[i][j];
                    j++;
                }
                i++;
            }

            temp.setItems(newArr);
            sum += neg * (items[avoid_x][avoid_y] * temp.determinant());
            for (int i = 0; i < cols; i++)
            {
                delete[] newArr[i];
            }
            delete[] newArr;
            avoid_y++;
            neg *= -1;
        }
        return sum;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] items[i];
        }
        delete[] items;
    }
};

int main()
{
    Matrix m(3, 3);

    m.takeInput();

    // m.display();
    // cout << endl;

    // m.transpose();

    m.display();

    cout << "Determinant: " << m.determinant() << endl;

    return 0;
}
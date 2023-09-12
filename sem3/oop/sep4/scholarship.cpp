#include <iostream>
#include <string.h>
using namespace std;

class Scholarship
{

    int id;
    char scholarship_name[20];
    float min_cgpa;
    float max_family_income;
    static int number_of_scholarships;

public:
    void getData()
    {
        id = number_of_scholarships;
        cout << "Enter the name of Scholarship: ";
        cin >> scholarship_name;
        cout << "Enter the minimum CGPA required for " << scholarship_name << ": ";
        cin >> min_cgpa;
        cout << "Enter the max family income for applicants: ";
        cin >> max_family_income;
    }

    void displayData()
    {
        cout << "Id: " << id << endl;
        cout << "Name of Scholarship: " << scholarship_name << endl;
        cout << "Minimum CGPA required for " << min_cgpa << endl;
        cout << "Max family income for applicants: " << max_family_income << endl;
    }

    static void showNumberOfScholarships()
    {
        cout << "\nScholarship programs existing in university: " << number_of_scholarships << endl;
    }

    Scholarship()
    {
        number_of_scholarships ++;
        this->getData();
    }
    ~Scholarship()
    {
        number_of_scholarships--;
        cout << scholarship_name << " scholarship was destroyed" << endl;
    }
};

int Scholarship::number_of_scholarships = 0;

int main()
{
    Scholarship sc1;
    {
        static Scholarship sc2;
    }
    Scholarship sc3;
    Scholarship::showNumberOfScholarships();
    return 0;
}

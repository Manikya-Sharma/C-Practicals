#include <iostream>
#include <string.h>
using namespace std;

class Scholarship
{
    int id;
    char scholarship_name[20];
    float min_cgpa;
    float max_family_income;
    static Scholarship *array_of_scholarships[50];
    static int number_of_scholarships;
public:
    static int ret_number_of_scholarships() {
        return number_of_scholarships;
    }
    static Scholarship** ret_array_of_scholarships() {
        return array_of_scholarships;
    }
    int ret_id() {
        return id;
    }
    char* ret_name() {
        return scholarship_name;
    }
    float ret_cgpa() {
        return min_cgpa;
    }
    float ret_income() {
        return max_family_income;
    }
    
    void getData();

    void displayData();

    static void showNumberOfScholarships()
    {
        cout << "\nScholarship programs existing in university: " << number_of_scholarships << endl;
    }

    static void showAvailableScholarships()
    {
        for (int i = 0; i < number_of_scholarships; i++)
        {
            Scholarship *sc = array_of_scholarships[i];
            sc->displayData();
            cout << endl;
        }
    }

    Scholarship()
    {
        array_of_scholarships[number_of_scholarships++] = this;
        this->getData();
    }
    ~Scholarship()
    {
        cout << scholarship_name << " was destroyed" << endl;
    }
};

void Scholarship::getData()
{
        id = number_of_scholarships;
        cout << "Enter the name of Scholarship: ";
        cin >> scholarship_name;
        cout << "Enter the minimum CGPA required for " << scholarship_name << ": ";
        cin >> min_cgpa;
        cout << "Enter the max family income for applicants: ";
        cin >> max_family_income;
        cout << endl;
}

void Scholarship::displayData() {
        cout << "Id: " << id << endl;
        cout << "Name of Scholarship: " << scholarship_name << endl;
        cout << "Minimum CGPA required for " << scholarship_name << endl;
        cout << "Max family income for applicants: " << max_family_income << endl;
        cout << endl;
}

int Scholarship::number_of_scholarships = 0;
Scholarship *Scholarship::array_of_scholarships[50];

class Student
{
private:
    char name[20];
    char dept[5];
    float cgpa;
    float family_income;
    Scholarship *sc;

public:
    Student();

    void allocate_scholarship();
    
    void display();
};

Student::Student()
{
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> dept;
        cout << "Enter family income:";
        cin >> family_income;
        cout << "Enter cgpa: ";
        cin >> cgpa;
        cout << "\nEnter the scholarship id you want to apply: " << endl;
        cout << "Available scholarships:-" << endl;
        Scholarship::showAvailableScholarships();
        allocate_scholarship();

    }

void Student::allocate_scholarship()
{
        int id;
        cin >> id;
        for (int i = 0; i < Scholarship::ret_number_of_scholarships(); i++)
        {
            if (Scholarship::Scholarship::ret_array_of_scholarships()[i]->ret_id() == id)
            {
                sc = Scholarship::Scholarship::ret_array_of_scholarships()[i];
                if (sc->ret_income() < family_income)
                {
                    cout << "Your family income is high and you are not eligible" << endl;
                    this->sc = NULL;
                    break;
                }
                else if (sc->ret_cgpa() > cgpa)
                {
                    cout << "Sorry your CGPA is less than required for this scholarship" << endl;
                    this->sc = NULL;
                    break;
                }
                cout << "Scholarship applied" << endl;
                break;
            }
            if (i == Scholarship::ret_number_of_scholarships() - 1)
            {
                cout << "No such scholarship found" << endl;
                this->sc = NULL;
            }
        }
}
void Student::display()
{
        cout << "Student " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Scholarship applied: " ;
        if (this->sc != NULL)
        {
            cout << this->sc->ret_name() << endl;
        }
        else
        {
            cout << "None"<<endl;
        }
    }

int main()
{
    Scholarship sc1;
    Scholarship sc2;
    Scholarship sc3;
    Student st1;
    Student st2;
    Student st3;
    st1.display();
    st2.display();
    st3.display();
    return 0;
}

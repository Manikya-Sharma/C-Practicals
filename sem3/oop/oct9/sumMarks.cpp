#include <iostream>
using namespace std;

class Student
{
    int marks;

public:
    Student() : marks(0) {}
    Student(int marks) : marks(marks) {}
    void display() { cout << "Marks: " << marks << endl; }
    Student operator+(Student s) { return marks + s.marks; }
};

int main()
{
    int marks;
    cout << "Enter narks of student 1: ";
    cin >> marks;
    Student s1(marks);

    cout << "Enter narks of student 2: ";
    cin >> marks;
    Student s2(marks);

    cout << "Enter narks of student 3: ";
    cin >> marks;
    Student s3(marks);

    Student s = s1 + s2 + s3;
    cout << "Sum of marks: -\n";
    s.display();
    return 0;
}
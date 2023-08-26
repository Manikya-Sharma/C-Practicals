#include <stdio.h>

struct Address
{
    int house_number;
    char road;
};

struct Student
{
    char name[20];
    char section;
    struct Address add;
};

struct Employee
{
    char name[20];
    char dept;
    struct Address add;
};

struct Address getAddress()
{
    struct Address addr;
    printf("Please enter addres details:-\n");
    printf("Enter the house number:");
    scanf("%d", &addr.house_number);
    printf("Enter the road (character):");
    scanf("%s", &addr.road);
    return addr;
}

void showAddress(struct Address *addr)
{
    printf("Residing at road %c, house number %d\n", addr->road, addr->house_number);
}

void setStudent(struct Student *st)
{
    printf("Enter the name of student:");
    scanf("%s", st->name);
    printf("Enter section:");
    scanf("%s", &st->section);
    st->add = getAddress();
}

void setEmployee(struct Employee *emp)
{
    printf("Enter the name of employee:");
    scanf("%s", emp->name);
    printf("Enter department:");
    scanf("%s", &emp->dept);
    emp->add = getAddress();
}

void displayStudent(struct Student *st)
{
    printf("Student name is %s\n", st->name);
    printf("Student has section %c\n", st->section);
    showAddress(&st->add);
}

void displayEmployee(struct Employee *emp)
{
    printf("Employee name is %s\n", emp->name);
    printf("Employee has department %c\n", emp->dept);
    showAddress(&emp->add);
}

int main()
{
    struct Student s;
    setStudent(&s);
    printf("\n\n");
    struct Employee emp;
    setEmployee(&emp);
    printf("\n\n");
    displayStudent(&s);
    printf("\n\n");
    displayEmployee(&emp);
    printf("\n\n");
    return 0;
}

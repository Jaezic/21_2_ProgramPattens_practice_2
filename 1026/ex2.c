#include <stdio.h>

typedef struct Employee
{
    char name[20];
    int age;
    int worked_years;
} EMP;

int main()
{
    EMP person;
    person.age = 20;
    person.worked_years = 1;
    return 0;
}
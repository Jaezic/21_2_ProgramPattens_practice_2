#include <stdio.h>
#include <string.h>

typedef struct student_record
{
    char Name[15];
    int id;
    char Dept[15];
    char gender;
} StudentRecord;

void main()
{
    StudentRecord Student1, Student2;
    strcpy(Student1.Name, "Won Park");
    Student1.id = 12345;
    strcpy(Student1.Dept, "SW");
    Student1.gender = 'M';
    strcpy(Student1.Dept, "SW");
    Student2 = Student1;
    printf("The student is ");
    if (Student2.gender == 'F')
        printf("Ms. ");
    else if (Student2.gender == 'M')
        printf("Mr. ");
    printf("%s\n", Student2.Name);
}
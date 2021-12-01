#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 10
#define NUM_HOBBY 4
#define MAX_AGE 100

struct PERSON
{
    char name[20];
    int age;
    char hobby[20];
};
const char *hobby[NUM_HOBBY] = {"swim", "music", "poker", "movie"};
int mingroup[NUM_HOBBY] = {0, 0, 0, 0};
void read_data(struct PERSON *person, int *num, const char *name)
{
    FILE *input;
    input = fopen(name, "r");
    if (input == NULL)
    {
        printf("Could not open the file : %s", name);
    }

    while (fscanf(input, "%s %d %s", person[*num].name, &person[*num].age, person[*num].hobby) != EOF)
    {
        (*num)++;
    }
    fclose(input);
    /* code here */
}

void print_out(struct PERSON *a, int num)
{
    for (int j = 0; j < NUM_HOBBY; j++)
    {
        int age = 999;
        for (int i = 0; i < num; i++)
        {
            if (strcmp(a[i].hobby, hobby[j]) == 0)
            {
                if (a[i].age < age)
                {
                    age = a[i].age;
                }
            }
        }
        mingroup[j] = age;
    }
    for (int j = 0; j < NUM_HOBBY; j++)
    {
        printf("%s Group=========\n", hobby[j]);
        printf("The min age is %d\n\n", mingroup[j]);
    }
    /* code here */
}

int main()
{
    int count = 0;
    struct PERSON person[MAX];

    // read data from person.txt
    read_data(person, &count, "person.txt");

    // get and the print the lowest age in the group
    print_out(person, count);

    return 0;
}

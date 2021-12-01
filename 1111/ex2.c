#include <stdio.h>
#define MAX 10

struct PERSON
{
    char name[20];
    int age;
    float salary;
};

void read_data(struct PERSON *person, const char *filename, int *count)
{
    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Could not open this file : %s", filename);
    }
    while (fscanf(input, "%s %d %f", person[*count].name, &person[*count].age, &person[*count].salary) != EOF)
    {
        (*count)++;
    }
    fclose(input);
}

void write_data(struct PERSON *person, const char *filename, int count)
{
    FILE *output;
    output = fopen(filename, "w");
    if (output == NULL)
    {
        printf("Could not open this file : %s", filename);
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%5s %5d %5.1f\n", person[i].name, person[i].age, person[i].salary);
    }
    fclose(output);
}

void update_data(struct PERSON *person, int count, int start, int end, float percent)
{
    for (int i = 0; i < count; i++)
    {
        if (person[i].age >= start && person[i].age <= end)
        {
            person[i].salary *= 1 + (percent / 100);
        }
    }
}

int main()
{
    struct PERSON person[MAX];
    int count = 0;
    read_data(person, "ex2_input.txt", &count);

    update_data(person, count, 10, 49, 10);
    write_data(person, "ex2_output.txt", count);
    return 0;
}
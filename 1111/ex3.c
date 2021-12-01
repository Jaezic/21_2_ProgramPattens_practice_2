#include <stdio.h>

#define MAX 50

struct PERSON
{
    char name[20];
    int age;
    float salary;
};
int read_data(struct PERSON *person, const char *filename)
{
    int count = 0;
    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Could not open this file : %s", filename);
    }
    while (fscanf(input, "%s %d %f", person[count].name, &person[count].age, &person[count].salary) != EOF)
    {
        (count)++;
    }
    return count;
    fclose(input);
}

void compare_data(struct PERSON *persona, struct PERSON *personb, int count, const char *filename)
{
    FILE *output;
    output = fopen(filename, "w");
    if (output == NULL)
    {
        printf("Could not open this file : %s", filename);
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%5s %5d %5.f -> %5.f\n", persona[i].name, persona[i].age, persona[i].salary, personb[i].salary);
    }
    fclose(output);
}
int main()
{
    struct PERSON persona[MAX];
    struct PERSON personb[MAX];
    int counta = read_data(persona, "ex3_input1.txt");
    int countb = read_data(personb, "ex3_input2.txt");
    compare_data(persona, personb, counta, "ex3_output.txt");
    return 0;
}
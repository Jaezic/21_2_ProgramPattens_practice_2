#include <stdio.h>

struct PERSON
{
    char name[20];
    int age;
    char hobby[20];
};
#define MAX 10

void init(struct PERSON *person, unsigned int *num, const char *name)
{
    FILE *input;
    input = fopen(name, "r");
    if (input == NULL)
    {
        printf("Could not open the file!\n");
    }
    int count = 0;
    while (fscanf(input, "%s %d %s", person[count].name, &person[count].age, person[count].hobby) != EOF)
    {
        printf("%s %d %s\n", person[count].name, person[count].age, person[count].hobby);
        count++;
    }
    *num = count;
    fclose(input);
}

void grouping(struct PERSON *person, unsigned int num, int step, int start, int end, const char *name)
{
    FILE *output;
    output = fopen(name, "w");
    if (output == NULL)
    {
        printf("Could not open the file!\n");
    }
    for (int j = start; j <= end; j += step)
    {
        fprintf(output, "\nAge From %d to %d\n", j, j + step - 1);
        fprintf(output, "-------------------------------\n");
        for (int i = 0; i < num; i++)
        {
            if (person[i].age >= j && person[i].age < (j + step))
            {
                fprintf(output, "%s %d %s\n", person[i].name, person[i].age, person[i].hobby);
            }
        }
    }
    fclose(output);
}
int main()
{
    struct PERSON person[MAX];
    unsigned int count = 0;
    init(person, &count, "ex3_input.txt");
    grouping(person, count, 5, 20, 45, "ex3_output.txt");
    return 0;
}
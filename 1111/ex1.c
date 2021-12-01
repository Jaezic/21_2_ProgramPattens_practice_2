#include <stdio.h>

struct PERSON
{
    char name[20];
    int age;
    char hobby[20];
};

struct PERSON_A
{
    char name[20];
    int age;
};

struct PERSON_B
{
    char name[20];
    char hobby[20];
};

void strcpy(char *a, char *b)
{
    int count = 0;
    while (b[count] != '\0')
    {
        a[count] = b[count];
        count++;
    }
    a[count] = '\0';
}
void init(struct PERSON *person, const char *filename, int *count)
{
    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Could not open the file!");
    }
    while (fscanf(input, "%s %d %s", person[*count].name, &person[*count].age, person[*count].hobby) != EOF)
    {
        printf("%s %d %s\n", person[*count].name, person[*count].age, person[*count].hobby);
        (*count)++;
    }
    fclose(input);
}

void gen_person_A(struct PERSON *person, struct PERSON_A *personA, int count)
{
    for (int i = 0; i < count; i++)
    {
        personA[i].age = person[i].age;
        strcpy(personA[i].name, person[i].name);
        printf("%s %d\n", personA[i].name, personA[i].age);
    }
}
void write_person_A(struct PERSON_A *personA, int count, const char *filename)
{
    FILE *output;
    output = fopen(filename, "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%s %d\n", personA[i].name, personA[i].age);
    }
    fclose(output);
}

void gen_person_B(struct PERSON *person, struct PERSON_B *personB, int count)
{
    for (int i = 0; i < count; i++)
    {
        strcpy(personB[i].hobby, person[i].hobby);
        strcpy(personB[i].name, person[i].name);
        printf("%s %s\n", personB[i].name, personB[i].hobby);
    }
}
void write_person_B(struct PERSON_B *personB, int count, const char *filename)
{
    FILE *output;
    output = fopen(filename, "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(output, "%s %s\n", personB[i].name, personB[i].hobby);
    }
    fclose(output);
}
#define MAX 50
int main()
{
    struct PERSON person[MAX];
    struct PERSON_A personA[MAX];
    struct PERSON_B personB[MAX];
    int count = 0;
    init(person, "ex1_input.txt", &count);
    printf("%d\n", count);
    gen_person_A(person, personA, count);
    write_person_A(personA, count, "ex1_output1.txt");
    gen_person_B(person, personB, count);
    write_person_B(personB, count, "ex1_output2.txt");

    return 0;
}
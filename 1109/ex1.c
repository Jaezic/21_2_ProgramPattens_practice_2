#include <stdio.h>
#include <string.h>

#define MAX 10

struct PERSON
{
    char name[20];
    int age;
    char hobby[20];
};

void swap(struct PERSON *a, struct PERSON *b)
{
    struct PERSON temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort_by_age(struct PERSON *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1].age > a[j].age)
                swap(&a[j - 1], &a[j]);
        }
    }
}
void sort_by_hobby(struct PERSON *a, int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (strcmp(a[j - 1].hobby, a[j].hobby) > 0)
                swap(&a[j - 1], &a[j]);
        }
    }
}

int main()
{
    FILE *input;
    struct PERSON person[MAX];
    input = fopen("ex1_input.txt", "r");
    if (input == NULL)
    {
        printf("Colud not open data.txt\n");
        return 0;
    }
    int count = 0;
    while (fscanf(input, "%s %d %s", person[count].name, &person[count].age, person[count].hobby) != EOF)
    {
        printf("%s %d %s\n", person[count].name, person[count].age, person[count].hobby);
        count++;
    }
    sort_by_hobby(person, count);
    printf("\nSort Result\n\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %s\n", person[i].name, person[i].age, person[i].hobby);
    }

    fclose(input);
    return 0;
}
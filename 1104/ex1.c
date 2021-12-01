#include <stdio.h>

struct CAR
{
    char name[20];
    int year;
};

int main()
{
    struct CAR car[2] = {{"Avante", 2007}, {"Sonata", 2008}};
    int i;
    FILE *myFile;
    myFile = fopen("ex1_output.txt", "w");
    if (myFile == NULL)
    {
        printf("File Could Not Be Opened");
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            fprintf(myFile, "%s %d\n", car[i].name, car[i].year);
        }
    }
    fclose(myFile);
    FILE *myFile2;
    myFile2 = fopen("ex1_output.txt", "r");
    if (myFile2 == NULL)
    {
        printf("File Could Not Be Opened");
    }
    else
    {
        char name[20];
        int year;
        while (fscanf(myFile, "%s %d\n", name, &year) != EOF)
        {
            printf("%s %d\n", name, year);
        }
    }
    return 0;
}
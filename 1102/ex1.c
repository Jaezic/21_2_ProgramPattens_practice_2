#include <stdio.h>

int main()
{
    int i;
    FILE *myFile;
    double price[2] = {139.25, 19.03};
    const char *description[2] = {"glove", "CD"};

    myFile = fopen("ex1_input.txt", "w");
    if (myFile == NULL)
        printf("\nFile Could Not Be Opened");
    else
    {
        for (i = 0; i < 2; i++)
        {
            fprintf(myFile, "%-9s %6.2f\n", description[i], price[i]);
        }
        fclose(myFile);
    }
}
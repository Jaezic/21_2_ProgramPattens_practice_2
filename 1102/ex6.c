#include <stdio.h>

int main()
{
    FILE *myFile;
    char ch;

    myFile = fopen("ex6_input.txt", "r");
    if (myFile == NULL)
        printf("\nCould not open file!\n");

    while ((ch = fgetc(myFile)) != EOF)
        putchar(ch);
    fclose(myFile);
    return 0;
}
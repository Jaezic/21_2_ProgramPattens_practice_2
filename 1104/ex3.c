#include <stdio.h>

int main()
{
    FILE *myInFile, *myOutFile;
    char ch;

    myInFile = fopen("ex3_input.txt", "r");
    if (myInFile == NULL)
    {
        printf("Could not open data.txt!\n");
    }
    myOutFile = fopen("ex3_output.txt", "w");
    if (myOutFile == NULL)
    {
        printf("Could not open samedata.txt!");
    }
    while ((ch = fgetc(myInFile)) != EOF)
    {
        fputc(ch, myOutFile);
    }
    fclose(myOutFile);
    fclose(myInFile);
    return 0;
}
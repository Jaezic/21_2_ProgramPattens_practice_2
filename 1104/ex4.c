#include <stdio.h>

int main()
{
    char inName[20];
    char outName[20];
    char ch;
    FILE *myInFile, *myOutFile;
    printf("Type the file name of source for copying:");
    scanf("%s", inName);
    printf("Type the file name of output:");
    scanf("%s", outName);

    myInFile = fopen(inName, "r");
    if (myInFile == NULL)
    {
        printf("Could not open data.txt\n");
    }
    myOutFile = fopen(outName, "w");
    if (myOutFile == NULL)
    {
        printf("Could not open samedata.txt!\n");
    }
    while ((ch = fgetc(myInFile)) != EOF)
        fputc(ch, myOutFile);
    fclose(myOutFile);
    fclose(myInFile);

    return 0;
}
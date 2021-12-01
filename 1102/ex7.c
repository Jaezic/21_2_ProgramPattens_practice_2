#include <stdio.h>

int main()
{
    FILE *myInFile, *myOutFile;
    char ch;

    myInFile = fopen("ex7_input.txt", "r");
    if (myInFile == NULL)
        printf("Could not open input file\n");
    myOutFile = fopen("ex7_output.txt", "w");
    if (myOutFile == NULL)
        printf("Could not open output file\n");

    while ((ch = fgetc(myInFile)) != EOF)
        fputc(ch, myOutFile);
    fclose(myOutFile);
    fclose(myInFile);
    return 0;
}
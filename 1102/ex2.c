#include <stdio.h>

int main()
{
    char a[20];
    int b;
    char c;
    int sum = 0;
    FILE *inFile;
    FILE *outFile;

    inFile = fopen("ex2_input.txt", "r");
    if (inFile == NULL)
    {
        printf("Input File Could Not Be Opened.");
    }
    outFile = fopen("ex2_output.txt", "a");
    if (outFile == NULL)
    {
        printf("Output File Could Not Be Opened.");
    }

    while (fscanf(inFile, "%s", a) != EOF)
    { // 한 단어씩 다 가져옴
        printf("%s\n", a);
    }
    while (fscanf(inFile, "%d", &b) != EOF)
    { // 한 숫자씩 다 가져옴
        sum = sum + b;
        printf("%d\n", b);
    }
    while (fscanf(inFile, "%c", &c) != EOF)
    { // 한 문자씩 다 가져옴
        printf("%c\n", c);
    }
    fprintf(outFile, "The sum is %d\n", sum);
    fclose(inFile);
    fclose(outFile);
    return 1;
}
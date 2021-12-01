#include <stdio.h>
int main()
{
    int i;
    FILE *myFile;
    myFile = fopen("ex5_input.txt", "r");
    if (myFile == NULL)
        printf("\nFile Could Not Be Opened\n");
    else
    {
        char ch = fgetc(myFile); // 한문자씩 다 가져옴
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(myFile);
        }
        printf("\nFinished printing the file\n");
    }
    fclose(myFile);
    return 0;
}
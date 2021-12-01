#include <stdio.h>

int main()
{
    FILE *infile;
    char line[100];
    int lcount = 0;
    if ((infile = fopen("ex3_input.txt", "r")) == NULL)
    {
        printf("File Could Not Be Opened.\n");
    }
    //각 라인을 읽어드림
    while (fgets(line, sizeof(line), infile) != NULL)
    {
        lcount++;
        printf("Line %d : %s", lcount, line);
    }
    fclose(infile);
    return 0;
}
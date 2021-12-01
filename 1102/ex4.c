#include <stdio.h>

int main()
{
    FILE *infile;
    FILE *outfile;
    char line[100];
    int lcount = 0;
    if ((infile = fopen("ex3_input.txt", "r")) == NULL)
    {
        printf("File Could Not Be Opened.\n");
    }
    if ((outfile = fopen("ex4_output.txt", "w")) == NULL)
    {
        printf("File Could Not Be Opened.\n");
    }
    //각 라인을 읽어드림
    while (fgets(line, sizeof(line), infile) != NULL)
    { // 한 라인씩 가져옴
        lcount++;
        printf("Line %d : %s", lcount, line);
        fprintf(outfile, "Line %d : %s", lcount, line);
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}
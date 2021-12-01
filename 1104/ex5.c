#include <stdio.h>
int main()
{
    FILE *myInFile;
    int groupNum = 0;

    myInFile = fopen("ex5_input.txt", "r");
    if (myInFile == NULL)
    {
        printf("Could not open data.txt!\n");
    }
    while (fscanf(myInFile, "%d", &groupNum) != EOF)
    {
        float sum = 0.0;
        int data = 0;
        for (int i = 0; i < groupNum; i++)
        {
            fscanf(myInFile, "%d", &data); // 어차피 문서 읽기 함수 특성상 커서가 넘어감.
            sum += data;
        }
        printf("Average=%f\n", sum / groupNum);
    }
    fclose(myInFile);
    return 0;
}
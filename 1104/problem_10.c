#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declare var
    int num = 0, sum = 0;
    int index = 0, grpindex = 0;
    int arr[100] = {0};
    float average[3] = {0.00};
    FILE *inputFile = NULL;
    FILE *reFile = NULL;
    // file input
    inputFile = fopen("problem_10_input.txt", "w");
    if (inputFile == NULL)
    {
        printf("Could not open samedata.txt!\n");
        exit(1);
    }
    else
    {
        fputs("5 96 87 78 93 21 4 92 82 85 87 6 72 69 85 75 81 73", inputFile);
    }
    fclose(inputFile);
    // file open
    reFile = fopen("problem_10_input.txt", "r");
    if (reFile == NULL)
    {
        printf("Could not open homework.txt!\n");
        exit(1);
    }
    else
    {
        // init array
        while (fscanf(reFile, "%d", &num) != EOF)
        {
            arr[index] = num;
            index++;
        }
        // scanning
        for (int i = 0; i < index; i++)
        {
            for (int j = 1; j <= arr[i]; j++)
            {
                average[grpindex] += arr[i + j];
                if (j == arr[i])
                {
                    average[grpindex] /= j;
                    grpindex++;
                    i += arr[i];
                    break;
                }
            }
        }
        // print array
        for (int i = 0; i < grpindex; i++)
        {
            printf("average[%d] : %.2f\n", i, average[i]);
        }
    }

    fclose(reFile);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 10
#define MAX_VALUE 150
#define MIN_VALUE 0

void read_data(float *arr, int *num, const char *name)
{ // arr: array, num: the number of data, name: file name
    /* Code here */
    FILE *input;
    input = fopen(name, "r");
    if (input == NULL)
    {
        printf("Could not open the file : %s", name);
    }
    int count = 0;
    while (fscanf(input, "%f ", &arr[count]) != EOF)
    {
        count++;
    }
    *num = count;
    fclose(input);
}

void update_value(float *arr, int num, float weight)
{ // arr: array, num: the number of data, weight: value to be multiplied
    /* Code here */
    for (int i = 0; i < num; i++)
    {
        arr[i] *= weight;
    }
}

void write_data(float *src, int num, const char *name)
{ // src: array, num: the number of data, name: file name
    /* Code here */
    FILE *output;
    output = fopen("sample_v2.txt", "w");
    if (output == NULL)
    {
        printf("Could not open the file : %s", name);
    }
    for (int i = 0; i < num; i++)
    {
        fprintf(output, "%f ", src[i]);
    }
    fclose(output);
}

void calc_ave(float *arr, int num, float *min, float *max, float *average)
{ // arr: array, num: the number of data, min: min value, max: max value, average: average value
    /* Code here */
    for (int i = 0; i < num; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
    float tmp = 0.0;
    for (int i = 0; i < num; i++)
    {
        tmp += arr[i];
    }
    *average = (tmp - *min - *max) / (num - 2);
}
int main()
{

    float arr[MAX] = {0.0};
    int num = 0;
    float min = 999, max = -1, average = 0.0;

    // read data
    read_data(arr, &num, "sample_v1.txt");

    // update and write data
    update_value(arr, num, 1.5);
    write_data(arr, num, "sample_v2.txt");

    // read data
    read_data(arr, &num, "sample_v2.txt");

    // caculate the average without min, max value
    calc_ave(arr, num, &min, &max, &average);

    // print the average, min, max values
    printf("The average=%f (min=%f max=%f excluded)\n", average, min, max);

    return 0;
}

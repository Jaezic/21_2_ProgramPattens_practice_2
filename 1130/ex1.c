#include <stdio.h>

void convert2v1(int num)
{
    int value = num;
    while (value != 0)
    {
        printf("%d", value & 1);
        value = (value >> 1);
    }
    printf("\n");
}
void convert2v2(int num)
{
    int value = num;
    int arr[100];
    int count = 0;
    while (value != 0)
    {
        arr[count] = (value & 1);
        value = (value >> 1);
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
int main()
{
    convert2v1(10);
    convert2v2(10);
    return 0;
}
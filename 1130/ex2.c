#include <stdio.h>
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
    int a = 10;
    int b = 15;
    convert2v2(a);
    convert2v2(b);
    printf("a & b = %d\n", (a & b));
    convert2v2(a & b);
    printf("a | b = %d\n", (a | b));
    convert2v2(a | b);
    printf("a ^ b = %d\n", (a ^ b));
    convert2v2(a ^ b);
    return 0;
}
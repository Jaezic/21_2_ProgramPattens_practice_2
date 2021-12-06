#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int *nums;
    printf("Type the number of elements : ");
    scanf("%d", &number);
    nums = (int *)malloc(number * sizeof(int));
    if (nums == (int *)NULL)
    {
        printf("malloc failed");
        exit(1);
    }
    for (int i = 0; i < number; i++)
    {
        printf("Type an integer:");
        scanf("%d", &nums[i]);
        printf("%d entered!\n", nums[i]);
    }
    free(nums);
    return 0;
}

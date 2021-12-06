#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
};
struct NODE *createNewNode(int key)
{
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}
struct NODE *buildingOneTwoThree()
{
    struct NODE *first = NULL;
    struct NODE *second = NULL;
    struct NODE *third = NULL;
    first = (struct NODE *)malloc(sizeof(struct NODE));
    second = (struct NODE *)malloc(sizeof(struct NODE));
    third = (struct NODE *)malloc(sizeof(struct NODE));
    first->key = 1;
    first->next = second;
    second->key = 2;
    second->next = third;
    third->key = 3;
    third->next = NULL;
    return first;
}

int Length(struct NODE *head)
{
    struct NODE *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void lengthTest()
{
    struct NODE *myList = buildingOneTwoThree();
    int len = Length(myList);
    printf("length of the list = %d\n", len);
}
int main()
{
    lengthTest();
}
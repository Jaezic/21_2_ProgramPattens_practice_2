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
struct NODE *buildingNode(int count)
{
    struct NODE *past = createNewNode(0);
    for (int i = 1; i < count; i++)
    {
        struct NODE *newnode = createNewNode(i);
        past->next = newnode;
        past = newnode;
    }
    return past;
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
struct NODE *attach(struct NODE *head, int index)
{
    struct NODE *ptr = head;
    int count = 0;
    if (Length(head) <= index)
    {
        printf("Can't found the Node\n");
        return head;
    }
    if (index == 0)
        return head;

    while (count < index)
    {
        count++;
        ptr = ptr->next;
    }
    return ptr;
}

int main()
{
    struct NODE *myList = buildingNode(10);
    int index = 7;
    printf("Node[%d] == %d\n", index, attach(myList, index)->key);
}
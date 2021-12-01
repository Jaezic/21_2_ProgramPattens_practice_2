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

int main()
{
    struct NODE *node = NULL;
    node = createNewNode(100);
    printf("%d\n", node->key);
    free(node);
    return 0;
}
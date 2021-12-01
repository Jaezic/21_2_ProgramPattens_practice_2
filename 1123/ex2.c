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
    struct NODE *node1 = NULL;
    struct NODE *node2 = NULL;
    node = createNewNode(100);
    node1 = createNewNode(200);
    node2 = createNewNode(300);
    // linking
    node->next = node1;
    node1->next = node2;
    printf("%d\n", node->key);
    printf("%d\n", node->next->key);
    printf("%d\n", node->next->next->key);
    free(node);
    free(node1);
    free(node2);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int key;
    struct NODE *next;
};
struct NODE *node;

int main()
{
    node = (struct NODE *)malloc(sizeof(struct NODE));
    if (node != (struct NODE *)NULL)
    {
        // (*node).key = 100;
        // (*node).next = NULL;
        // printf("key=%d next=%d\n", (*node).key, (*node).next);

        //==== 위 아래가 똑같다.
        node->key = 100;
        node->next = NULL;
        printf("key=%d next=%d\n", node->key, node->next);
        free(node);
    }
}
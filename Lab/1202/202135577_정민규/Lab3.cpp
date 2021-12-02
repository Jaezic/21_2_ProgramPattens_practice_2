#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NUM 5

struct NODE
{
	int key;
	struct NODE *next;
};

struct NODE *createNewNode(int key)
{
	struct NODE *addinstance = (struct NODE *)malloc(sizeof(struct NODE));
	addinstance->key = key;
	addinstance->next = NULL;
	return addinstance;
}

void addNode(struct NODE *head, struct NODE *node)
{
	struct NODE *prev = NULL;
	while (head != NULL)
	{
		if (head->key > node->key)
		{
			break;
		}
		prev = head;
		head = head->next;
	}
	if (prev != NULL)
		prev->next = node;
	node->next = head;
}

void deleteNode(struct NODE *head, int key)
{
	struct NODE *prev = NULL;
	while (head != NULL)
	{
		if (head->key == key)
		{
			prev->next = head->next;
			break;
		}
		prev = head;
		head = head->next;
	}
}

void displayList(struct NODE *head)
{
	while (head != NULL)
	{
		printf("[%d] --> ", head->key);
		head = head->next;
	}
	printf("[NULL]\n");
}

int main()
{
	int i = 0;
	struct NODE *head;
	struct NODE *tmp;

	// Initialize node
	head = createNewNode(0);
	for (i = 1; i < NUM; i++)
	{
		tmp = createNewNode(i * 10);
		addNode(head, tmp);
	}
	displayList(head);

	// Add node
	tmp = createNewNode(15);
	addNode(head, tmp);
	tmp = createNewNode(25);
	addNode(head, tmp);
	displayList(head);

	// delete node
	deleteNode(head, 30);
	deleteNode(head, 40);
	displayList(head);
	return 0;
}

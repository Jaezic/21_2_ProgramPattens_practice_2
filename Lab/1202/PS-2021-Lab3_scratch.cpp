#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NUM 5

struct NODE {
	int key;
	struct NODE* next;
};

struct NODE* createNewNode(int key) {
}

void addNode(struct NODE* head, struct NODE* node) {
}

void deleteNode(struct NODE* head, int key) {
}

void displayList(struct NODE* head) {
}

void main() {
	int i = 0;
	struct NODE* head;
	struct NODE* tmp;

	// Initialize node
	head = createNewNode(0);
	for (i = 1; i < NUM; i++) {
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
}


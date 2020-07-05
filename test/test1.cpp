#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX_SIZE 100

typedef struct node Node;
typedef int ct;

struct node {
	ct value;
	int dum;
	struct node * next;
	struct node * prev;
};


void enqueue(Node * tail, ct value) {
	Node * n_node = (Node*)malloc(sizeof(Node));
	n_node->dum = 0;
	n_node->value = value;

	n_node->next = tail;
	n_node->prev = tail->prev;
	tail->prev = n_node;
	n_node->prev->next = n_node;
}

void dequeue(Node * head, Node * end) {

	while (head->dum == 1) {
		if (head == end) {
			printf("empty\n");
			return;
		}
		head = head->next;
	}
	printf("\nDequeue %c\n", head->value);
	head->prev->next = head->next;
	head->next->prev = head->prev;
	free(head);

}
void print_queue(Node * head, Node * end) {
	printf("Queue: ");
	while (head != end) {
		if (head->dum == 0) {
			printf("%c ", head->value);
		}
		head = head->next;
	}
	printf("\n");
}
int main() {
	Node * p[6];
	for (int i = 5; i >= 0; --i) {
		p[i] = (Node*)malloc(sizeof(Node));
		p[i]->value = 0;
		p[i]->dum = 1;
	}
	for (int i = 5; i >= 0; --i) {
		if (i<5) {
			p[i]->next = p[i + 1];
		}
		else {
			p[i]->next = NULL;
		}
		if (i>0) {
			p[i]->prev = p[i - 1];
		}
		else {
			p[i]->prev = NULL;
		}
	}

	int n;
	int flag = 1;
	while (flag) {

		printf("\nchoose function\n1. enqueue\n2. dequeue\n3. print_queue\n0. exit\n");
		scanf("%d", &n);
		getchar();
		if (n == 1) {
			ct value;
			ct priority;
			printf("input value \n");
			scanf("%c", &value);
			getchar();
			printf("input priority \n");
			scanf("%d", &priority);
			getchar();
			enqueue(p[priority], value);
		
		}
		else if (n == 2) {
			dequeue(p[0], p[5]);

		}
		else if (n == 3) {
			print_queue(p[0], p[5]);
		}
		else if (n == 0) {
			flag = 0;
		}
	}
	return 0;
}


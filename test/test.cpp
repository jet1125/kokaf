#include <iostream>

using namespace std;
typedef struct node Node;

struct node{
	//int size;
	int dum;
	int value;
	struct node *next;
	struct node *prev;

};


int main(){
	int arr[5];
	for(int i = 0; i < 5; i ++){
		Node *n_node = (*Node)malloc(sizeof(Node));
		n_node->dum = i;
		n_node->value = i * 2;
		arr[i] = *n_node;
	}
}
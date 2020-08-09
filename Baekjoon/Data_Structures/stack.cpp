#include <iostream>

using namespace std;


typedef struct node Node;

struct node {
	//int size;
	int value;
	struct node *next;

};

void push(Node * top, int value){
	Node * n_node = (Node*)malloc(sizeof(Node));
	n_node->value = value;
	n_node->next = top->next;
	top->next = n_node;
	
	top->value --;
}

void pop(Node * top){
	
	if(top->value == 0){
		cout << -1 << endl;
	}
	
	else{
		cout << top->next->value << endl;
		Node * tmp = top->next;
		top->next = tmp->next;
		free(tmp);
		
		top->value ++;
		
		// if(top->value == 0){
		// 	top->next = NULL;
		// }
	}
}

void size(Node * top){
	int size = top->value * -1;
	cout << size << endl;
}

void empty(Node * top){
	
	if(top->value < 0)
		cout << 0 << endl;
	
	else
		cout << 1 << endl;

}

void top(Node * top){
	
	if(top->value == 0){
		cout << -1 << endl;
	}
	
	else{
		cout << top->next->value << endl;
	}
}

int main(){
	Node * head;
	head = (Node*)malloc(sizeof(Node));
	head->value = 0;
	head->next = NULL;
	int N = 0;
	string c;
	cin >> N;
	
	for (int i = 0; i < N; i ++){
		cin >> c;
		if(c == "push"){
			int X;
			cin >> X;
			
			push(head, X);
		}
		else if(c == "pop"){
			pop(head);
		}
		else if(c == "size")
			size(head);
		
		else if(c  == "empty")
			empty(head);
		
		else if(c == "top")
			top(head);
	}		
	
	
}
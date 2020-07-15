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

void push(Node * tail, int value){
	Node * n_node = (Node *)malloc(sizeof(Node));
	n_node->value = value;
	n_node->dum - 0;
	n_node->next = tail->next;
	n_node->next->prev = n_node;
	n_node->prev = tail;
	n_node->prev->next = n_node;
}

void pop(Node * head){
	
	if(head->prev->dum == 1)
		cout << -1 << endl;
	
	else{
		
		cout << head->prev->value << endl;
		
		Node * tmp = head->prev;
		tmp->prev->next = head;
		tmp->next->prev = tmp->prev;
		// tmp->next = NULL;
		// tmp->prev = NULL;
		free(tmp);
	}
	
	
	
}

void size(Node * tail){
	
	int cnt = 0;
	Node * tmp = tail->next;
	
	while(tmp->dum == 0){
		tmp = tmp->next;
		cnt ++;
	}
	
	cout << cnt << endl;
	
}

void empty(Node * head){
	
	if(head->prev->dum == 1)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

void front(Node * head){
	
	if(head->prev->dum == 1)
		cout << -1 << endl;
	else
		cout << head->prev->value << endl;
	
}


void back(Node * tail){
	
	if(tail->next->dum == 1)
		cout << -1 << endl;
	else
		cout << tail->next->value << endl;
	
}


int main(){
	Node * head;
	Node * tail;
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	tail->next = head;
	head->next = NULL;
	head->prev = tail;
	tail->prev = NULL;
	head->dum = 1;
	tail->dum = 1;
	
	int N = 0;
	string c;
	cin >> N;
	
	for (int i = 0; i < N; i ++){
		cin >> c;
		if(c == "push"){
			int X;
			cin >> X;
			push(tail, X);
			
		}
		else if(c == "pop"){
			pop(head);
		}
		else if(c == "size")
			size(tail);
		
		else if(c  == "empty")
			empty(head);
		
		else if(c == "front")
			front(head);
		
		else if(c == "back")
			back(tail);
		
	}
	
}
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

void push_front(Node * head, int value){
	Node * n_node = (Node *)malloc(sizeof(Node));
	n_node->value = value;
	n_node->dum = 0;
	n_node->prev = head->prev;
	n_node->prev->next = n_node;
	n_node->next = head;
	n_node->next->prev = n_node;
}

void push_back(Node * tail, int value){
	Node * n_node = (Node *)malloc(sizeof(Node));
	n_node->value = value;
	n_node->dum = 0;
	n_node->next = tail->next;
	n_node->next->prev = n_node;
	n_node->prev = tail;
	n_node->prev->next = n_node;
}

void pop_front(Node * head){
	
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

void pop_back(Node * tail){
	
	if(tail->next->dum == 1)
		cout << -1 << endl;
	
	else{
		
		cout << tail->next->value << endl;
		
		Node * tmp = tail->next;
		tmp->next->prev = tail;
		tmp->prev->next = tmp->next;
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
		if(c == "push_front"){
			int X;
			cin >> X;
			push_front(head, X);
			
		}
		
		else if(c == "push_back"){
			int X;
			cin >> X;
			push_back(tail, X);
			
		}
		
		else if(c == "pop_front"){
			pop_front(head);
		}
		
		else if(c == "pop_back"){
			pop_back(tail);
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
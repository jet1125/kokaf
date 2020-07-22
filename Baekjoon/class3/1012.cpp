#include <iostream>

using namespace std;

typedef struct node Node;

struct node{
	//int size;
	//int dum;
	int value;
	int cor[2];
	struct node *next;
	struct node *prev;
	struct node *up;
	struct node *down;

};

int main(){
	
	int T;
	
	cin >> T;
	
	for(int i = 0; i < T; i ++){
		Node * head;	
		head = (Node*)malloc(sizeof(Node));
		head->value = 0;
		head->cor = {0,0};
		
		int M, N, K;
		
		cin >> M >> N >> K;
		
		for(int i = 0; i < M; i ++){
			for(int j = 0; j < N; j ++){
				
				Node * n_node, tmp;
				if(i == 0 && j == 0){
					n_node = head;	
					
				}
				else{
					n_node = (Node*)malloc(sizeof(Node));
					tmp->down = n_node;
					n_node->up = tmp;
					n_node->cor = {i,j};
				}
				tmp = n_node;
				
				
			}
			
		}
		
	
		for (int j = 0; j < K; j ++){
			
		}
		
		
	}
	
	
}
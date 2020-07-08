#include <iostream>

using namespace std;
int cnt = 0;

int find_min(int A[], int B[], int N, int M){
	int min = 9;
	int location = 0;
	int temp = 0;

	for(int i = 9; i > A[M]; i --){
		//temp = 0;
		for(int j = 0; j < N; j ++){
		
			if(A[(location +j) % N] == i){
				
				temp = (location + j) % N;
		
			}
		}
		location = temp;
	}
	
	return location;
}



int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i ++){
		
		int N, M;
		cin >> N >> M;
		
		int A[N];
		int B[N];
		cnt = 0;
		int locate = 0;
		
		
		for(int i = 0; i < N; i ++){
			cin >> A[i];
			B[i] = 0;
			
		}
		
		
		for(int i = 0; i < N; i ++){
			if(A[M] == A[i]){
				B[i] = 1;
			}
			else if(A[M] < A[i]){
				cnt ++;
				B[i] = 2;
			}
		}
		

	
		int j = 0;
		locate = find_min(A, B, N, M);
		//cout << locate << endl;
		//cout << (locate+j)%N << endl;
		while((locate+j)%N != M){
			
			if(B[(locate+j) % N] == 1)
				cnt ++;

			j++; 
			
		}
		
		 cout << (cnt + 1) << endl;
	}
	
}
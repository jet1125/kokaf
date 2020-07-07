#include <iostream>

using namespace std;
int cnt = 0;

int find_min(int A[], int B[], int N){
	int min = 10;
	int locate;
	for(int i = 0; i < N; i ++){
		if(B[i]==2 && A[i] <= min){
			min = A[i];
			locate = i;
			
		}
	}
	return locate;
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
		
		// for(int i = 0; i < N; i ++){
		// 	cout << A[i];
			
		// }
		// cout << endl;
		
		// for(int i = 0; i < N; i ++){
		// 	cout << B[i];
			
		// }
		// cout << endl;
		
	
		int j = 1;
		locate = find_min(A, B, N);
		// cout << locate << endl;
		// cout << cnt << endl;
		while((locate+j)%N != M){
			if(B[(locate+j) % N] == 1)
				cnt ++;
			//cout << ((locate+j)%N) << endl;
			//cout << B[(locate+j) % N] << endl;
			j++; 
		}
		
		 cout << (cnt + 1) << endl;
	}
	
}
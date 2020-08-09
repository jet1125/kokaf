#include <iostream>

int main(){
	
	int N, M;
	int ** arr = nullptr;
	
	cin >> M >> N;
	
	arr = new *int [M];
	for(int i = 0; i < M; i ++){
		arr[i] = new int [N];
	}
	
	
}
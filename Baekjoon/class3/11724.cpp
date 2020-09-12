#include <iostream>
//#include <stack>
using namespace std;

void DFS(int ** arr, int * vis, int N, int pivot){
	vis[pivot] = 1;
	for(int i = 0; i < N; i ++){
		if(arr[pivot][i] == 1 && vis[i] == 0){
			DFS(arr, vis, N, i);
			
		}
	}
	
}

int main(){
	
	int N, M;
	cin >> N >> M;
	int ** arr = nullptr;
	arr = new int*[N];
	for(int i = 0; i < N; i ++){
		arr[i] = new int[N];
	}
	int* vis = nullptr;
	vis = new int[N];
	//vis = {0,};
	for(int i = 0; i < M; i ++){
		int x, y;
		cin >> x >> y;
		arr[x-1][y-1] = 1;
		arr[y-1][x-1] = 1;		 
		
	}

	int cnt = 0;
	for(int i = 0; i < N; i ++){
		if(vis[i] != 1){
			
			DFS(arr, vis, N, i);
			cnt ++;
		}
	}
	

	cout << cnt << endl;
}
#include <iostream>
#include <queue>

using namespace std;


int find_cnt(int **arr, int * vis, int N){
	int cnt = 0;
	queue<int> Q;
	Q.push(0);
	vis[0] = 1;
	int size = 1;
	while(!Q.empty()){
		int a = 0;
		for(int i = 0; i < size; i ++){
			int tmp = Q.front();
			//cout << "F" << tmp << endl;
			Q.pop();
			for(int j = 0; j < N; j ++){
				if(arr[tmp][j] == 1){
					
					arr[tmp][j] = 0;
					arr[j][tmp] = 0;
					
					if(vis[j] != 1){
						Q.push(j);
						cnt ++;
						a ++;
						vis[j] = 1;
					}
				}
				
			}
		}
		size = a;
	}
	return cnt;
}

int main(){
	
	int N, K;
	cin >> N >> K;
	int ** arr = nullptr;
	int *vis = nullptr;
	
	arr = new int *[N];
	vis = new int[N];
	for(int i = 0; i < N; i ++){
		arr[i] = new int[N];
	}
	
	for(int i = 0; i < K; i ++){
		int m, n;
		cin >> m >> n;
		arr[m - 1][n - 1] = 1;
		arr[n - 1][m - 1] = 1;
	}
	
	
	
// 	for(int i = 0; i < N; i ++){
// 		for(int j = 0; j < N; j ++){
// 			cout << arr[j][i] << " ";
// 		}
// 		cout << endl;
// 	}
	 
	cout << find_cnt(arr, vis, N);
}
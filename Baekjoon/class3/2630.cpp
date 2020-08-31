#include <iostream>
#include <queue>

using namespace std;

int move_x[4] = {1, 0, -1, 0};
int move_y[4] = {0, -1, 0, 1};


int find_cnt(int** arr, int** vis, int N){
	
}


int main(){
	int N;
	cin >> N;
	
	int** arr = nullptr;
	arr = new int*[N];
	for(int i = 0; i < N; i ++){
		arr[N] = new int[N];
	}
	
	int** vis = nullptr;
	vis = new int*[N];
	for(int i = 0; i < N; i ++){
		vis[N] = new int[N];
	}
	
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			cin >> arr[j][i];
		}
	}
	
	cout << find_cnt(arr, vis, N);
}
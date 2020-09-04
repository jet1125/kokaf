#include <iostream>
#include <queue>

using namespace std;

int cnt_W, cnt_B = 0;

void find_cnt(int** arr, int x, int y, int N){
	
	int w = 0;
	int b = 0;
	for(int i = x; i < x + N; i ++){
		for(int j = y; j < y + N; j ++){
			
			if(arr[j][i])
				b ++;
			if(!arr[j][i])
				w ++;
		}
	}
	if(b == N * N){
		cnt_B ++;
	}
	else if(w == N * N)
		cnt_W ++;
	else{
		find_cnt(arr, x, y, N / 2);
		find_cnt(arr, x + N /2, y, N / 2);
		find_cnt(arr, x, y + N /2, N / 2);
		find_cnt(arr, x + N / 2, y + N / 2 , N / 2);
	}
}


int main(){
	int N;
	cin >> N;
	
	int** arr = nullptr;
	arr = new int*[N];
	for(int i = 0; i < N; i ++){
		arr[i] = new int[N];
	}
	
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++){
			cin >> arr[j][i];
		}
	}
	
	
	find_cnt(arr, 0, 0, N);
	
	cout << cnt_W << endl;
	cout << cnt_B;
}
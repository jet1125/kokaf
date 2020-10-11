#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	int ** arr = nullptr;
	arr = new int*[N + 1];
	for(int i = 0; i < N + 1; i ++){
		arr[i] = new int[K + 1]; 
	}
	
	pair<int, int>* node = nullptr;
	node = new pair<int, int>[N];
	
	for(int i = 0; i < N; i ++){
		cin >> node[i].first >> node[i].second;
		memset(arr[i], 0, sizeof(int) * K);
	}
	
	
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= K ; j ++){
			arr[i][j] = arr[i - 1][j];
			if(j - node[i - 1].first >= 0){
				arr[i][j] = max(arr[i][j], arr[i - 1][j - node[i - 1].first] + node[i - 1].second);
			}
		}
			
	}
	cout << arr[N][K] << endl;
}
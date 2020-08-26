#include <iostream>
#include <math.h>

using namespace std;

int move_x[4] = {0, 1, -1, 1};
int move_y[4] = {0, 0, 1, 0};

int main(){
	int N;
	int a;
	int b;
	cin >> N >> a >> b;
	int **arr = nullptr;
	int size = pow(int(2), int(N)); 
	arr = new int*[size];
	
	for(int i= 0; i < size; i ++){
		arr[i] = new int[size];
	}
	
	//int cnt = 0;
	int cur_x = 0;
	int cur_y = 0;
	int k = 0;
	int q = 0;
	int x = 0;
	int y = 0;
	for(int i = 0; i < size * size; i ++){
		k = i % 4;
		q = i / 4;
		if(k == 0){
			cur_x = cur_x + (move_x[q] * N);
			cur_y = cur_y + (move_y[q] * N); 
			x = cur_x;
			y = cur_y;
		}
		x = x + move_x[k];
		y = y + move_y[k];
		arr[x][y] = i;
	
	}

	cout << arr[a][b];
	// for(int i = 0; i < size; i ++){
	// 	for(int j = 0; j < size; j ++){
	// 		cout << arr[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
}
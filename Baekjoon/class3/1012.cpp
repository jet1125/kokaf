#include <iostream>

using namespace std;

void find_m(int** arr, int x, int y, int m, int n){
	
	if(x < m-1){
		if(arr[x+1][y] == 1){
			find_m(arr, x+1, y, m, n);
		}
	
	}
	if(y < n -1){
		if(arr[x][y+1] == 1){
			find_m(arr, x, y+1, m, n);
		}
	}
	
	arr[x][y] = 0;
}


int main(){
	int T;
	cin >> T;
	for(int l = 0; l < T; l ++){
		int** arr = nullptr;
		int m, n, k;
		int cnt;
		cin >> m >> n >> k;
		arr = new int* [m];  //x = (int*)malloc(sizeof(int)*5);
		for(int i =0; i < m; i ++){
			arr[i] = new int[m];
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
			}
		}
		
		for(int i = 0; i < k; i ++){
			
			int x,y;
			
			cin >> x >> y;
			
			arr[x][y] = 1;
		}
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(arr[j][i] == 1){
					find_m(arr, j, i, m, n);
					cnt ++;
				}
			}
			
		}
		
		
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		std::cout << arr[j][i]<<" ";
		// 	}
		// 	std::cout << std::endl;
		// }
		
		
		cout << cnt << endl;
		
		
		
		for (int i = 0; i < n; i++)
			delete [] arr[i];
		delete [] arr;

	}


}

// http://blog.naver.com/PostView.nhn?blogId=chansung0602&logNo=221022228017

//https://twinparadox.tistory.com/439
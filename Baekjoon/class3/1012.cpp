#include <iostream>
#include <string.h>
using namespace std;


int arr[51][51];
int vis[51][51];


void find_m(int x, int y, int m, int n){
	
	if(x < m-1){
		if(arr[x+1][y] == 1 && vis[x+1][y] == 0){
			find_m(x+1, y, m, n);
		}
	
	}
	if(y < n -1){
		if(arr[x][y+1] == 1 && vis[x][y+1] == 0){
			find_m(x, y+1, m, n);
		}
	}
	
	vis[x][y] = 1;
}

int main(){
	int T;
	cin >> T;
	for(int l = 0; l < T; l ++){
		//int** arr = nullptr;
		//int** vis = nullptr;
		int m, n, k;
		int cnt;
		cin >> m >> n >> k;
		//arr = new int* [m];  //x = (int*)malloc(sizeof(int)*5);
		
		// vis = new int* [m]; 
		// for(int i =0; i < m; i ++){
		// 	arr[i] = new int[m];
		// 	vis[i] = new int[m];
		// }

		// for (int i = 0; i < m; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		arr[i][j] = 0;
		// 		vis[i][j] = 0;
		// 	}
		// }
		memset(arr,0,sizeof(arr));
        memset(vis,0,sizeof(vis));
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
				if(arr[j][i] == 1 && vis[j][i] == 0){
					find_m(j, i, m, n);
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
		
		
		cout << cnt << "\n";
		
		
		
		// for (int i = 0; i < n; i++)
		// 	delete [] arr[i];
		// delete [] arr;

	}


}

// http://blog.naver.com/PostView.nhn?blogId=chansung0602&logNo=221022228017

//https://twinparadox.tistory.com/439
#include <iostream>
//#include <string.h>
using namespace std;


//int arr[51][51];
//int vis[51][51];


void find_m(int** arr, int** vis, int x, int y, int m, int n){
	
	if(x < m-1){
		if(arr[x+1][y] == 1 && vis[x+1][y] == 0){
			vis[x][y] = 1;
			find_m(arr, vis, x+1, y, m, n);
		}
		else
			vis[x+1][y] = 1;
	
	}
	if(y < n -1){
		if(arr[x][y+1] == 1 && vis[x][y+1] == 0){
			vis[x][y] = 1;
			find_m(arr, vis, x, y+1, m, n);
		}
		else
			vis[x][y+1] = 1;
	}
	
	if(x > 0){
		if(arr[x-1][y] == 1 && vis[x-1][y] == 0){
			vis[x][y] = 1;
			find_m(arr, vis, x-1, y, m, n);
		}
		else
			vis[x-1][y] = 1;
	}
	
	if(y > 0){
		if(arr[x][y-1] == 1 && vis[x][y-1] == 0){
			vis[x][y] = 1;
			find_m(arr, vis, x, y-1, m, n);
		}
		else
			vis[x][y-1] = 1;
	}
	vis[x][y] = 1;
	arr[x][y] = 0;
}

int main(){
	int T;
	cin >> T;
	for(int l = 0; l < T; l ++){
		int** arr = nullptr;
		int** vis = nullptr;
		int m, n, k;
		int cnt;
		cin >> m >> n >> k;
		arr = new int* [m];  //x = (int*)malloc(sizeof(int)*5);
		
		vis = new int* [m]; 
		for(int i =0; i < m; i ++){
			arr[i] = new int[m];
			vis[i] = new int[m];
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		//memset(arr,0,sizeof(arr));
        //memset(vis,0,sizeof(vis));
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
					find_m(arr, vis, j, i, m, n);
					cnt ++;
				}
				else
					vis[j][i] = 1;
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
		
		
		
		for (int i = 0; i < n; i++){
			delete [] arr[i];
			delete [] vis[i];
		}
		delete [] arr;
		delete [] vis;

	}


}

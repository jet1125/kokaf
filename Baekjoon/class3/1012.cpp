#include <iostream>
//#include <time.h>
//#include <string.h>
//#include <time.h>
using namespace std;


//int arr[51][51];
//int vis[51][51];

int moveX[4] = { 0, 1, 0, -1 };
int moveY[4] = { 1, 0, -1, 0 };

void find_m(int** arr, int x, int y, int m, int n){
	if(arr[x][y] == 1){
		arr[x][y] = 0;
		for(int i = 0; i < 4; i ++){
			int a = moveX[i] + x;
			int b = moveY[i] + y;
			if(a>=0 && b>= 0 && a < m && b < n){
				find_m(arr, a, b, m, n);
			}
		}	
	}
}

int main(){
	//time_t start, end;
	//double result;
	int T;
	cin >> T;
	for(int l = 0; l < T; l ++){
		//start = time(NULL);
		int** arr = nullptr;
		//int** vis = nullptr;
		int m, n, k;
		int cnt;
		cin >> m >> n >> k;
		arr = new int* [m];  //x = (int*)malloc(sizeof(int)*5);
		
		//vis = new int* [m]; 
		for(int i =0; i < m; i ++){
			arr[i] = new int[n];
			//vis[i] = new int[m];
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
				//vis[i][j] = 0;
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
		
		
		cout << cnt << "\n";
		
		
		
		for (int i = 0; i < m; i++){
			delete [] arr[i];
			//delete [] vis[i];
		}
		delete [] arr;
		//delete [] vis;
		//end = time(NULL);
		//result = (double)(end - start);
		//cout << result << endl;

	}


}



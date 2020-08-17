#include <iostream>
#include <queue>

using namespace std;


int total = 0;
int moveX[4] = { 0, 1, 0, -1 };
int moveY[4] = { 1, 0, -1, 0 };

queue<pair<int,int>> Q; 
//Q.push(make_pair(x,y)); 
// Q.pop(); //Q에 들어있는 pair 사용 법 
// pair<int, int> tmp = Q.front(); 
// int x = tmp.first; 
// int y = tmp.second;

void bfs(int **arr, int M, int N){
	int size, cnt = 0;
	
	while(!Q.empty()){
		size = Q.size();
		total += size;
		if(total == M*N){
			cout << cnt;
			break;
		}
		
		for(int k = 0; k < size; k ++){
			pair<int, int> tmp = Q.front();
			int curx = tmp.first;
			int cury = tmp.second;
			Q.pop();
			for(int i = 0; i < 4; i ++){
				int a = moveX[i] + curx;
				int b = moveY[i] + cury;
				if(a>=0 && b>= 0 && a < M && b < N){
					if(arr[a][b] == 0){
						Q.push(make_pair(a, b));
						//total ++;
						arr[a][b] = 1;
					}
				}	
			}
		}
		
		cnt ++;
		
		
		
	}
	
	if(total != M*N){
		cout << -1 <<endl;
	}
	
	
}


int main(){
	
	int **arr = nullptr;
	int **vis = nullptr;
	int M, N;
	
	cin >> M >> N;
	
	arr = new int* [M];
	vis = new int* [M];
	for(int i = 0; i < M; i ++){
		arr[i] = new int [N];
		vis[i] = new int [N];
	}
	
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < M; j ++){
			int k;			
			cin >> k;
			if(k == 1){
				arr[j][i] = 1;
				Q.push(make_pair(j,i));
				//total ++;
			}
			
			else if(k == -1){
				arr[j][i] = -1;
				total ++;
			}
			
			else
				arr[j][i] = 0;
			
			//vis[j][i] = 0;
		}
		
	}
	
	bfs(arr, M, N);
	

	
	
	
	// for(int i = 0; i < N; i ++){
	// 	for(int j = 0; j < M; j ++){
	// 		//int k;			
	// 		cout << arr[j][i];
	// 	}
	// 	cout << endl;
		
	// }

}
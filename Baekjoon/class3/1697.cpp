#include <iostream>
#include <queue>

using namespace std;


int find_min(int N, int K){
	int arr[100001] = {0, };
	
	queue<int> Q;
	int cnt = 1;
	Q.push(N);
	int size = 1;
	int flag = 1;
	while(!Q.empty() && flag){
		
		int a = 0;
		for(int i = 0; i < size; i ++){
			
			int tmp = Q.front();
			//cout << tmp << endl;
			Q.pop();
			arr[tmp] = cnt;
			if(tmp == K){
				//cout << "bb" << endl;
				
				flag = 0;
				break;
			}	
		
			else{
				if(tmp * 2 <= 100000 && tmp * 2 >= 0 && arr[tmp * 2] == 0){
					Q.push(tmp * 2);
					a ++;
				}	
				if(tmp + 1 <= 100000 && tmp+ 1 >= 0 && arr[tmp + 1] == 0){
					Q.push(tmp + 1);
					a ++;
				}	
				if(tmp - 1 <= 100000 && tmp - 1 >= 0 && arr[tmp - 1] == 0){
					Q.push(tmp - 1);
					a ++;
				}	
			}
		}
		size = a;
		
		cnt ++;
		//cout << "cnt" << cnt << endl;
	}
	
	return arr[K];
}

int main(){
	
	int N, K;
	cin >> N >> K;
	
	cout << find_min(N, K) - 1<< endl;
		
}
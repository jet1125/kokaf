#include <iostream>
#include <algorithm>


using namespace std;


int main(){
	//vector<pair<int, int>> v;	
	int N;
	cin >> N;
	int * arr = nullptr;
	arr = new int[N];
	for(int i = 0; i < N; i ++){
		
		cin >>arr[i];
		
	}
	
	sort(arr, arr + N);
	
	int ans = 0;
	for(int i = 0; i < N; i ++){
		int cnt = i;
		while(cnt >= 0){

			ans = ans + arr[cnt];
			cnt --;
		}
	}
	
	cout << ans << endl;
}
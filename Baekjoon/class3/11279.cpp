#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue <int, vector<int>> pq;
	int cnt = 0;
	for(int i = 0; i < N; i ++){
		int k;
		cin >> k;
		
		if(k > 0){
			pq.push(k);
			cnt ++;
		}
		
		else if(cnt == 0 && k == 0){
			cout << 0 << "\n";
		}
		
		else if(k == 0){
			cout << pq.top() << "\n";
			pq.pop();
			cnt --;
		}
	}
}
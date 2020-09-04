#include <iostream>
#include <queue>

using namespace std;



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T, cnt = 0;
	priority_queue<int, vector <int>, greater<int> > pq;
	cin >> T;
	
	for(int i = 0; i < T; i ++){
		int k;
		cin >> k;
		if(k == 0 && cnt > 0){
			cout << pq.top() << "\n";
			pq.pop();
			cnt --;
		}
		else if(cnt == 0 && k == 0){
			cout << 0 << "\n";
		}
		else if(k > 0){
			pq.push(k);
			cnt ++;
		}
		
		
	}
}
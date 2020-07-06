#include <iostream>
#include <queue>

using namespace std;

int main(){

	// 큐 생성
	queue<int> q;
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	// push
	q.push(a);
	q.push(b);
	q.push(c);
	q.push(d);
	q.push(e);
	q.push(f);


	// pop
	q.pop();
	q.pop();
	q.pop();


	// front
	cout << "front element : " << q.front() << '\n';


	// back
	cout << "back element : " << q.back() << '\n';


	// size
	cout << "queue size : " << q.size() << '\n';


	// empty
	cout << "Is it empty? : " << (q.empty() ? "Yes" : "No") << '\n';

	return 0;

}
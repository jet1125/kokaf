#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 300000;

void Dijkstra(vector<pair<int, int>> G[], int* d, int V, int s) {
	priority_queue<pair<int,int>> pq;
	for (int i = 0; i < V; i++) {
		
		d[i] = INF;
	}

	d[s] = 0;
	pq.push(make_pair(0, s));

	
	while (!pq.empty()) {
		pair <int, int> tmp = pq.top();
		pq.pop();

		for (int i = 0; i < G[tmp.second].size(); i++) {
			int cur_point = G[tmp.second][i].first;
			int cur_len = G[tmp.second][i].second;
			if (d[cur_point] < cur_len)
				continue;
			if (cur_point != tmp.second ) {
				int len = -tmp.first + cur_len;
				if (len < d[cur_point]) {
					d[cur_point] = len;
					pq.push(make_pair(-len, cur_point));
				}

			}
		}
	}
}

int main() {
	int V, E, s;
	
	cin >> V >> E;
	cin >> s;
	vector<pair<int, int>> G[20001];

	int* d = nullptr;
	d = new int[V];

	

	for (int k = 0; k < E; k++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a - 1].push_back(make_pair(b - 1, c));
	}

	Dijkstra(G, d, V, s - 1);

	for (int i = 0; i < V; i++) {
		if (d[i] == INF)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}

	delete[] d;

}

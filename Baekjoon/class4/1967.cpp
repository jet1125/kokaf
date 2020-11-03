#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int, int>> G[10002];
int visited[10002] = { 0, };
int ans, end_point;

void dfs(int point, int length) {

    if (visited[point])
        return;

    visited[point] = 1;
    if (ans < length) {
        ans = length;
        end_point = point;
    }

    for (int i = 0; i < G[point].size(); i++) {
        dfs(G[point][i].first, length + G[point][i].second);
    }
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int parent, child, len;
		cin >> parent >> child >> len;
		G[parent].push_back(make_pair(child, len));
		G[child].push_back(make_pair(parent, len));
	}

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));

    dfs(end_point, 0);
    cout << ans << endl;

}
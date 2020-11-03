	#include <iostream>

	using namespace std;

	const int INF = 10000000;


	void short_path(int** G, int N) {
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (G[i][j] > G[i][k] + G[k][j])
						G[i][j] = G[i][k] + G[k][j];
 				}
			}
		}
	}

	int main() {
		int N, M;
		cin >> N >> M;

		int** G = nullptr;
		G = new int*[N];

		for (int i = 0; i < N; i++) {
			G[i] = new int[N];
		}
		int a, b, c;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				G[i][j] = INF;

				if (i == j)
					G[i][j] = 0;
			
			}
		}

		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			if (G[a - 1][b - 1] > c)
				G[a - 1][b - 1] = c;
		}
	
		short_path(G, N);


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (G[i][j] == INF)
					G[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << G[i][j] << " ";
			}
			cout << endl;
		}


	}
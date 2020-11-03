#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>


using namespace std;
const int MAX = 1000000;

char S[MAX + 1], W[MAX + 1];
int F[MAX];


void fail(int M) {
	
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		
		for (int j = 1; j < i + 1; j++) {
			int tmp = 0;
			for (int k = 1; k < j + 1; k++) {
				if (W[k - 1] == W[i - j + k]) {
					cnt = j;
					tmp++;
				}
				else {
					
					break;
				}
			}
			if(tmp == j)
				F[i] = cnt;
			
		}
		
		
	}

}
//
//ABCDABD
int main() {

	int N, M;
	fgets(S, sizeof(S), stdin);
	fgets(W, sizeof(W), stdin);
	N = strlen(S) - 1;
	M = strlen(W) - 1;
	//cout << S[0] << endl;


	fail(M);

	int point = 0;
	int ans_t = 0;
	vector<int> ans_pos;
	while (point < (N - M + 1)) {
		int fail = -1;
		for (int i = 0; i < M; i++) {
			if (S[point + i] != W[i]) {
				fail = i;
				break;
			}
		}

		if (fail > 0) {
			point = point + fail - F[fail - 1];
		}

		else if (fail == 0)
			point++;
		else {
			ans_t++;
			ans_pos.push_back(point + 1);
			point = point + M;
		}
	}
	cout << ans_t << endl;

	for (int i : ans_pos)
		cout << i << endl;

}



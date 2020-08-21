#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int MAX = 1000000;
int n;
pair<int,int> heap[1000000];

void swap(int i1, int i2) {
	pair<int, int> tmp = heap[i1];
	heap[i1] = heap[i2];
	heap[i2] = tmp;
	return;
}

void max_heap(int cur, int size) {
	while (cur < size) {
		int left = cur * 2 + 1;
		int right = cur * 2 + 2;
		if (left < size || right < size) {
			int tmp = cur;
			if (left < size) {
				if (heap[left].first > heap[tmp].first) tmp = left;
			}
			if (right < size) {
				if (heap[right].first > heap[tmp].first) tmp = right;
			}
			if (tmp == cur) break;
			swap(cur, tmp);
			cur = tmp;
		}
		else break;
	}
	return;
}

void heapify() {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		max_heap(i, n);
	}
	return;
}

int main() {
	memset(heap, 0, sizeof(heap));
	scanf("%d", &n);
	

	for (int i = 0; i < n; i++) {
		scanf("%d", &heap[i].first);
		heap[i].second = heap[i].first;
	}
	heapify();
	for (int i = n - 1; i > 0; i--) {
		swap(0, i);
		max_heap(0, i);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", heap[i].first);
	}
	return 0;
}
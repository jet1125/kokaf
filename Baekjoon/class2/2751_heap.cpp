#include <iostream>
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

using namespace std;

void heapify(int arr[], int p, int heapsize){
	int left = p * 2;
	int right = p * 2 + 1;
	int temp;
	if(left <= heapsize && arr[left-1] > arr[p-1])
		SWAP(arr[left-1], arr[p-1], temp);
	
	if(right <= heapsize && arr[right-1] > arr[p-1])
		SWAP(arr[right-1], arr[p-1], temp);
	
}

void build_heap(int arr[], int heapsize){
	
	for(int i = heapsize / 2; i > 0 ; i --){
		heapify(arr, i, heapsize);
		
	}
	// for (int i = 0; i < heapsize; i ++)
	// 	cout << arr[i];
}

int main(){
	
	int N, temp;
	 cin >> N;
	int * arr = nullptr;
	arr = new int[N];
	
	for(int i = 0; i < N; i ++){
		cin >> arr[i];
		
	}
	for(int i = N; i > 0; i --){
		
		build_heap(arr, i);
		//cout << arr[0] << endl;
		SWAP(arr[0], arr[i - 1], temp);
		//cout << arr[N-i];	
	}
	
	for (int i = 0; i < N; i ++)
		cout << arr[i] << "\n";
	
	
}
#include <iostream>
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )


using namespace std;


void heapify(pair<int, int> arr[], int p, int heapsize){
	int left = p * 2;
	int right = p * 2 + 1;
	int largest;
	int temp;
	largest = p;
	if(left <= heapsize && arr[left-1].first < arr[largest-1].first)
		//SWAP(arr[left-1], arr[p-1], temp);
		largest = left;
	if(right <= heapsize && arr[right-1].first < arr[largest-1].first)
		largest = right;
	
	if(largest != p){
		int tmp;
		tmp = arr[largest-1].first;
		arr[largest-1].first = arr[p-1].first;
		arr[p-1].first = tmp;
		
		tmp = arr[largest-1].second;
		arr[largest-1].second = arr[p-1].second;
		arr[p-1].second = tmp;
		//SWAP(arr[largest-1], arr[p-1], temp);
	}	
}

void build_heap(pair<int, int> arr[], int heapsize){
	
	for(int i = heapsize / 2; i > 0 ; i --){
		heapify(arr, i, heapsize);
		
	}
	// for (int i = 0; i < heapsize; i ++)
	// 	cout << arr[i];
}

int main(){
	int N;
	int tmp;
	cin >> N;
	pair<int, int>* arr = nullptr;
	arr = new pair<int, int>[N];
	//int *arr_sub = nullptr;
	//arr_sub = new int[N];
	
	for(int i = 0; i < N; i ++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i = N; i > 0; i --){
		
		build_heap(arr, i);
		//cout << arr[0] << endl;
		//SWAP(arr[0], arr[i - 1], temp);
		tmp = arr[0].first;
		arr[0].first = arr[i-1].first;
		arr[i-1].first = tmp;
		
		tmp = arr[0].second;
		arr[0].second = arr[i-1].second;
		arr[i-1].second = tmp;
		//cout << arr[N-i];	
		
	}
	
	for(int i = 0; i < N; i ++){
		cout << arr[i].first << arr[i].second << endl;
	}
	delete[] arr;
	
}
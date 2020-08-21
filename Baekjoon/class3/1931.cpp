#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


void max_heap(pair<int, int> arr[], int p, int heapsize){
	while(p <= heapsize){
		int left = p * 2 + 1;
		int right = p * 2 + 2;
		int largest;
		
		if(left < heapsize || right < heapsize){
			largest = p;
			if(left < heapsize && arr[left].second > arr[largest].second)
		//SWAP(arr[left-1], arr[p-1], temp);
				largest = left;
			if(right < heapsize && arr[right].second > arr[largest].second)
				largest = right;
	
			if(largest == p)
				break;
		
			
			pair<int, int> tmp = arr[largest];
			arr[largest] = arr[p];
			arr[p] = tmp;
			p = largest;
			
		}
		
		else
			break;
	}
	
}

void heapify(pair<int, int> arr[], int heapsize){
	
	for(int i = (heapsize-1) / 2; i >= 0 ; i --){
		max_heap(arr, i, heapsize);
		
	}
	
}


int reservation_max(pair<int, int> arr[], int size){
	int max = 0;
	int pivot = 2^31 - 1;
	//pair<int, int> * arr_sub = nullptr;
	//arr_sub = new pair<int, int>[size + 1];
	//arr_sub[size].first = 0;
	//arr_sub[size].second = pivot;
	for(int i = size-1; i >= 0; i --){
		if(arr[i].second <= pivot){
			max ++;
			pivot = arr[i].first;
		}
	}
	return max;
}

int main(){
	int N;
	pair<int, int> tmp;
	cin >> N;
	pair<int, int>* arr = nullptr;
	arr = new pair<int, int>[N];
	//int *arr_sub = nullptr;
	//arr_sub = new int[N];
	
	for(int i = 0; i < N; i ++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	heapify(arr, N);
	
	for(int i = N - 1; i >= 0; i --){
		
		
		//cout << arr[0] << endl;
		//SWAP(arr[0], arr[i - 1], temp);
		
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i]= tmp;
		//cout << arr[N-i];	
		max_heap(arr, 0, i);
	}
	
	//int cur = arr[N-1].second;
	pair<int, int> * sort = nullptr;
	sort = new pair<int, int>[N];
	int cur_pos = N - 1;
	int k = 0;
	for(int i = N - 1; i > 0; i --){
		if(arr[i -1].second == arr[cur_pos].second){
			sort[k].first = 
			k ++;
		}
		
		else{
			cur_pos = i;
		}
	}
	int i = N -1;
	while(i > 0){
		if(arr)
	}
	
	for(int i = 0; i < N; i ++){
		cout << arr[i].first << " " << arr[i].second << endl;
		
	}
	
	cout << reservation_max(arr, N) << endl;
	delete[] arr;
	
}
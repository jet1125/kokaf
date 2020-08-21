#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;



int reservation_max(pair<int, int> arr[], int size){
	int max = 0;
	int pivot = 0;
	//pair<int, int> * arr_sub = nullptr;
	//arr_sub = new pair<int, int>[size + 1];
	//arr_sub[size].first = 0;
	//arr_sub[size].second = pivot;
	for(int i = 0; i < size; i ++){
		if(arr[i].first >= pivot){
			max ++;
			pivot = arr[i].second;
			//cout << arr[i].second;
		}
	}
	return max;
}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){   //이름이 같으면, 나이가 적은순
        return a.first < b.first;
    }else{                  //이름 다르면, 이름 사전순
        return a.second < b.second;
    }
    
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
	
	sort(arr, arr + N, compare);
	
	
	for(int i = 0; i < N; i ++){
		cout << arr[i].first << " " << arr[i].second << endl;
	}
	
	cout << reservation_max(arr, N) << endl;
	delete[] arr;
	
}
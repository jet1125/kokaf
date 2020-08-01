#include <iostream>
#include <algorithm>


using namespace std;

int main(){
	
	int N;
	
	cin >> N;
	int *arr = nullptr;
	arr = new int[N];
	
	for(int i = 0; i < N; i ++){
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
		
	}
	
	cout << *min_element(arr, arr + N) << endl;
	cout << *max_element(arr, arr + N) << endl;
	
}
#include<iostream>

using namespace std;
int arr[1001];

int cnt(int N){
	if(N == 1 || N == 2)
		return arr[N];
	
	else{
		for(int i = 3; i <= N; i ++){
			arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
		}
	}
	return arr[N];
	
}

int main(){
	arr[1] = 1;
	arr[2] = 2;
	int N;
	cin >> N;
	cout << cnt(N)<< endl;
}
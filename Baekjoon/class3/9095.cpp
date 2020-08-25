#include <iostream>

using namespace std;
int divide(int k){
	if(k == 1) return 1;
	else if(k == 2) return 2;
	else if(k == 3) return 4;
	else{
		return divide(k - 1) + divide(k - 2) + divide(k - 3);
	}
	
}
int main(){
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		int k;
		cin >> k;
		
		cout << divide(k) << endl;
	}
	
}
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool prime(int N){
	if(N<=1) {
        return false;
    }

    for(int i=2; i<=sqrt(N); i++) {
        if((N%i)==0) {
            return false;
        }
    }

    return true;
}

bool palindrome(string s){
	bool b = true;
	for(int i = 0; i < s.size() / 2; i ++){
		if(s[i] != s[s.size() - i - 1]){
			b = false;
			break;
		}
	}
	
	return b;
}
int main(){
	int pr[1003002];
	for(int i = 0; i < 1003001; i ++){
		if(prime(i + 1) == true)
			pr[i + 1] = 1;
		else
			pr[i + 1] = 0;
	}
	int N;
	cin >> N;
	while(true){
		N ++;
		string s = to_string(N);
		if(palindrome(s) == true && pr[N] == 1){
			break;
			
		}
		
	}
	for(int i = 0; i < N; i ++){
		if(pr[i + 1] == 1){
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	cout << N << endl;
}
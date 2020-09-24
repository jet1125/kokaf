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
	
	int N;
	cin >> N;
	while(true){
		
		if(prime(N) == true){
			
			string s = to_string(N);
			if(palindrome(s) == true){
				break;	
			}
			
		}
		N ++;
	}
	
	cout << N << endl;
}
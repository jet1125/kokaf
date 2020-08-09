#include <iostream>

using namespace std;

void fibonacci(int n, int cnt[], int fi_0[], int fi_1[]) {
    if (n == 0) {
        
		cnt[0] ++;
        
    } 
	else if (n == 1) {
        
		cnt[1] ++;
        
    } 
	else {
		if(fi_0[n] == 0){
        	
			fibonacci(n-2, cnt, fi_0, fi_1);
			fi_0[n-2] = cnt[0];
			fi_1[n-2] = cnt[1];
			
			fibonacci(n-1, cnt, fi_0, fi_1);
			fi_0[n-1] = cnt[0];
			fi_1[n-1] = cnt[1];
		}
		else{
			cnt[0] = fi_0[n];
			cnt[1] = fi_1[n];
		}
    }
}

int main(){
	
	int T;
	cin >> T;
	int fi_0[40] = {0,};
	int fi_1[40] = {0,};
	fi_0[0] = 1;
	fi_0[1] = 1;
	
	for(int i = 0; i < T; i ++){
		int cnt[2] = {0, 0};
		
		
		int N;
		cin >> N;
		
		fibonacci(N, cnt, fi_0, fi_1);
		fi_0[N] = cnt[0];
		fi_1[N] = cnt[1];
		
		cout << fi_0[N] << " " << fi_1[N] << "\n";
		
		
	}
}
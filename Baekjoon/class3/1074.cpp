#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int N;
	int a;
	int b;
	cin >> N >> a >> b;
	int size = pow(int(2), int(N));
	int k = size;
	int s = 0;
	int cnt = 0;
	while(k > 0){
		if(a < (k / 2) && b < (k / 2)){
			s = 0;
			
		}
			
		else if(a < (k / 2) && b >= (k / 2)){
			s = 1;
			b = b - k / 2;
		}
			
		else if(a >= (k / 2) && b < (k / 2)){
			s = 2;
			a = a - k / 2;
		}
			
		else if(a >= (k / 2) && b >= (k / 2)){
			s = 3;
			a = a - k / 2;
			b = b - k / 2;
		}
			
		cnt = cnt + s * (k / 2) * (k / 2);
		
		k = k / 2;
	}
	
	cout << cnt;

}
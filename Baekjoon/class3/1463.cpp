#include <iostream>
#include <algorithm>

using namespace std;

int arr[12] = {0, 1, 1, 2, 3, 2, 3, 3, 2, 3, 4, 3};
int make_1(int N, int cnt, int flag){
	int a, b, c;
	
	if(flag == 3){
		return 1000000;
	}
	if(N == -1){
		return 1000000;
	}
	else if(N == 1){
		return cnt;
	}
	
	else {
		if(N < 13){
			return cnt + arr[N - 1];
		}
		else{
			if(N % 2 == 0){
				cnt ++;
				flag = 0;
				a = make_1(N/2, cnt, flag);
				cnt --;
			}
		
			else{
				a = make_1(-1, cnt, flag);
			}
		
			if(N % 3 == 0){
				cnt ++;
				flag = 0;
				b = make_1(N/3, cnt, flag);
				cnt --;
			}
		
			else{
				b = make_1(-1, cnt, flag);
			}
			cnt ++;
			flag ++;
			c = make_1(N - 1, cnt, flag);
			cnt --;
		
			//cout << a << " " << b << " " << c << endl;
		
			return min({a, b, c});
		}
	}
	
	
	
	
}

int main(){
	
	int N;
	cin >> N;
	int cnt = 0;
	int flag = 0;
	cout << make_1(N, cnt, flag) << endl;
}
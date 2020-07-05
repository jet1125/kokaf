#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	
	int a, b, c;
	int mul, j, k;
	int array[10];
	for(int i=0;i < 10; i++){
		array[i] = 0;
	}
		
	cin >> a;
	cin >> b;
	cin >> c;
	mul = a * b * c;
	j = 10;

	while(mul){
		
		k = mul % 10;
		array[k] ++;
		mul = mul/10;
	}
	
	for(int i=0; i<10; i++){
		cout << array[i] <<endl;
	}
	
	return 0;
}
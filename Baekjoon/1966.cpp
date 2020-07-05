#include <iostream>

using namespace std;

int main(){
	
	int x = 5;
	int* ptr = &x;
	//int ptr1 = &x;
	//std::cout << x << endl;
	std::cout << &x << endl;
	std::cout << ptr << endl;	
	//std::cout << ptr1 << endl;
	return 0;
}
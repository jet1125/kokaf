#include <iostream>
#include <string>

using namespace std;

int main(){
	int a = 12345;
	string b;
	b = to_string(a);
	
	cout << b[0] << endl;
	cout << b.size() << endl;
}
#include <iostream>

using namespace std;
int main() {
	while (true) {
		string a;
		int temp = 0;
		cin >> a;
		if (a == "0")	break;
		for (int i = 0; i < a.size() / 2; i++) {
			if (a[i] != a[a.size() - i - 1])	
				temp = 1;
		}
		if(temp == 1)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	
	}
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <algorithm>



using namespace std;
bool compare(string a, string b){
    if(a.size() <= b.size()){   //이름이 같으면, 나이가 적은순
        return a < b;
    }
	else{                  //이름 다르면, 이름 사전순
        return a > b;
    }
    
}



int main(){
	vector<string> v(3);
	
	for(int i = 0; i < 3; i ++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), greater<>());
	for(int i = 0; i < 3; i ++){
		cout << v[i] << v[i].length() << endl;
	}
	
	
}
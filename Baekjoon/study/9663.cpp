#include <iostream>
using namespace std;
int N;
int result=0;
int col[15];
 
bool ispossible(int i){
    for(int j=0; j<i; j++) {
        if (col[i] == col[j] || i - j == abs(col[i] - col[j])){
			cout << "f" << endl;
            return false;
		}
    }
	cout << "t" << endl;
    return true;
 
}
 
void nqueen(int i){
    if(i==N)
        result++;
    else{
        for(int j=0; j<N; j++){
            col[i]=j;
            if(ispossible(i)){
				for(int k = 0; k < N; k ++){
					cout << col[k];
				}
				cout << endl;
                nqueen(i+1);
            }
        }
    }
}
 
int main(void){
    cin>>N;
    nqueen(0);
	cout << endl;
    cout<<result<<"aa" << endl;
}

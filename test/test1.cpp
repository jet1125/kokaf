#include <iostream>

using namespace std;


int main(){
	int** x = nullptr;
	int m,n;
	std::cin >> m >> n;
	x = new int* [m];  //x = (int*)malloc(sizeof(int)*5);
	for(int i =0; i < m; i ++){
		x[i] = new int[m];
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[i][j] = i*n +j;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << x[i][j]<<" ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < m; i++)
		delete [] x[i];
	delete [] x;




}

// http://blog.naver.com/PostView.nhn?blogId=chansung0602&logNo=221022228017

//https://twinparadox.tistory.com/439
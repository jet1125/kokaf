#include <iostream>

using namespace std;


int main(){
	int *x = nullptr;
	int n;
	std::cin >> n;
	x = new int[n];  //x = (int*)malloc(sizeof(int)*5);

	for (int i = 0; i < n; i++)
	{
		x[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout<<x[i]<<" ";
	}
	std::cout << std::endl;
	delete[] x;

}

// http://blog.naver.com/PostView.nhn?blogId=chansung0602&logNo=221022228017

//https://twinparadox.tistory.com/439
// 打印九九乘法表

#include<iostream>
#include<string>
using namespace std;

int main()
{	
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << j*i << " ";
		}
		
		cout << endl;
	}
	
	return 0;
}
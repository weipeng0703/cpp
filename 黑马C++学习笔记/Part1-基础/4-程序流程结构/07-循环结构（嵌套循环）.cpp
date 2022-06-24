/*
作用： 在循环体中再嵌套一层循环，解决一些实际问题
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	// 利用嵌套循环实现星图

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << endl;
		
	}
	

	return 0;
}

// 案例描述：从1开始数到数字100，如果数字个位含有7,或者数字十位含有7，或者该数字是7的倍数，
// 我们打印敲桌子，其余数字直接打印输出。

#include<iostream>
#include<string>
using namespace std;

int main()
{	
	for (int i = 1; i < 101; i++)
	{
		if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0)   //可以写在一起的
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
		
	}
	
	
	return 0;
}
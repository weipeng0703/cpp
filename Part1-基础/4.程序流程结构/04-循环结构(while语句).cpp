/*
 **作用：**满足循环条件，执行循环语句

语法：while(循环条件){ 循环语句 }

解释：只要循环条件的结果为真，就执行循环语句
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 0;

	while (num < 10)
	{
		cout << num <<endl;
		num++;
	}
	
	return 0;
}

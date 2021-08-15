/*
作用： 满足循环条件，执行循环语句

语法： do{ 循环语句 } while(循环条件);

**注意：**与while的区别在于do…while会先执行一次循环语句，再判断循环条件
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 0;

	do
	{
		cout << num << endl;
		num++;
	} while (num);

	// 与while循环区别在于，do…while先执行一次循环语句，再判断循环条件
	while (num)      //故当初始num==0的时候，循环无法开始执行
	{
		cout << num << endl;
		num++;
	}

	return 0;
}

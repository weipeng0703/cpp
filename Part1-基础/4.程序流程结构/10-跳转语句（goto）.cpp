/*
**作用：**可以无条件跳转语句

语法： goto 标记;

**解释：**如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "1." << endl;

	cout << "2." << endl;

	goto FLAG;

	cout << "3." << endl;

	cout << "4." << endl;

	FLAG:
	cout << "5." << endl;

	return 0;
}
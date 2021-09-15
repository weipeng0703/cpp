/*
**作用：**在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;      //筛选条件，执行到此不再向下执行，执行下一次循环
			// break;      //continue并没有使整个循环终止，而break会跳出循环
		}
		
		cout << i << endl;
	}
	
	return 0;
}
/*
作用: 用于跳出选择结构或者循环结构

break使用的时机：

1.出现在switch条件语句中，作用是终止case并跳出switch
2.出现在循环语句中，作用是跳出当前的循环语句
3.出现在嵌套循环中，跳出最近的内层循环语句
*/
#include<iostream>
#include<string>
using namespace std;

// 1.出现在switch语句中
// int main()
// {
// 	cout << "请选择游戏难度" << endl;
// 	cout << "1.简单" << endl;
// 	cout << "2.中等" << endl;
// 	cout << "3.困难" << endl;

// 	int select = 0;
// 	cin >> select;

// 	switch (select)
// 	{
// 	case 1:
// 		cout << "您选择的是简单难度" << endl;
// 		break;
// 	case 2:
// 		cout << "您选择的是中等难度" << endl;
// 		break;
// 	case 3:
// 		cout << "您选择的是困难难度" << endl;
// 		break;
// 	default:
// 		break;
// 	}


// 	return 0;
// }


// 2.出现在循环语句中

// int main()
// {
// 	for (int i = 0; i < 10; i++)
// 	{
// 		// 如果i=5，退出循环，不再打印

// 		if (i == 5)
// 		{
// 			break;
// 		}
		
// 		cout << i << endl;

// 	}

// 	return 0;
// }

// 3.出现在嵌套循环中

int main()
{
	// 利用嵌套循环实现星图

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			
			cout << "* ";
		}
		cout << endl;
		
	}
	
	return 0;
}
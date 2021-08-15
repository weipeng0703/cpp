// 系统随机生成一个1到100之间的数字，玩家进行猜测
// 如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	// 添加随机数种子，利用当前系统时间生成随机数，防止每次生成的随机数一样

	srand((unsigned int)time(NULL));

	// 1.生成随机数
	int num = rand()%100 + 1;     //生成0+1~99+1的随机数
	
	// cout << num <<endl;
	
	// 2.玩家输入数据
	int val = 0; 

	while (1)
	{
		cin >> val;

		if (val > num)
	{
		cout << "猜测过大" << endl;
	}
	else if (val < num)
	{
		cout << "猜测过小" << endl;
	}
		else
	{
		cout << "猜测正确" << endl;
		break;      //猜测正确即退出循环
	}

	}

	return 0;
}
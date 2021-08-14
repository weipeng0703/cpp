/*
**作用：**执行多条件分支语句

语法：

switch(表达式)

{

	case 结果1：执行语句;break;

	case 结果2：执行语句;break;

	...

	default:执行语句;break;

}
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	//请给电影评分 
	//10 ~ 9   经典   
	// 8 ~ 7   非常好
	// 6 ~ 5   一般
	// 5分以下 烂片

	// （1）提示用户打分

	cout << "请给电影打分（0~10以内的整数）：" <<endl;

	// （2）用户打分

	int score = 0;

	cin >> score;

	cout << "您的打分为：" << score << endl;

	// （3）根据分数提示结果

	switch (score)
	{
		case 10: 
			cout << "您认为这是一部经典电影" << endl;
			break;   // 退出当前分支
		case 9: 
			cout << "您认为这是一部经典电影" << endl;
			break;
		case 8: 
			cout << "您认为这电影非常好" << endl;
			break;
		case 7: 
			cout << "您认为这部电影非常好" << endl;
			break;	
		case 6: 
			cout << "您认为这部电影及格" << endl;
			break;
		case 5: 
			cout << "您认为这部电影一般" << endl;
			break;
		default:
			cout << "您认为这是一部烂片" << endl;
	}

	return 0;
}

// 注意1：switch语句中表达式类型只能是整型或者字符型

// 注意2：case里如果没有break，那么程序会一直向下执行

// 总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，
//      缺点是switch不可以判断区间
// **作用：**执行满足条件的语句

// if语句的三种形式

// 1.单行格式if语句

// 2.多行格式if语句

// 3.多条件的if语句

#include<iostream>
#include<string>
using namespace std;

// ​1.单行if语句
// 单行格式if语句：if(条件){ 条件满足执行的语句 }

// int main()
// {
//     int score = 0;
//     cout << "please enter a score：" << endl;
//     cin >> score;

//     cout << "the score you input is ：" << score << endl;

//     if (score > 600)
//     {
//         cout << "Congratulations!" << endl;
//     }

//     // system("pause");
//     return 0;
// }

// ​2.多行if语句
// if(条件){ 条件满足执行的语句 }else{ 条件不满足执行的语句 };
// int main()
// {
//     int score = 0;
//     cout << "please enter a score：" << endl;
//     cin >> score;

//     cout << "the score you input is ：" << score << endl;

//     if (score > 600)
//     {
//         cout << "Congratulations!" << endl;
//     }
//     else
//     {
//         cout << "Sorry for you." << endl;
//     }

//     // system("pause");
//     return 0;
// }

// ​3.多条件的if语句
// if(条件1){ 条件1满足执行的语句 }
// else if(条件2){条件2满足执行的语句}
// ... 
// else{ 都不满足执行的语句}

// int main() 
// {

// 	int score = 0;

// 	cout << "请输入考试分数：" << endl;

// 	cin >> score;

//     cout << "考试分数为：" << score << endl;

// 	if (score > 600)
// 	{
// 		cout << "我考上了一本大学" << endl;
// 	}
// 	else if (score > 500)
// 	{
// 		cout << "我考上了二本大学" << endl;
// 	}
// 	else if (score > 400)
// 	{
// 		cout << "我考上了三本大学" << endl;
// 	}
// 	else
// 	{
// 		cout << "我未考上本科" << endl;
// 	}

// 	// system("pause");

// 	return 0;
// }


// 4.嵌套if语句

// 在if语句中，可以嵌套使用if语句，达到更精确的条件判断

int main()
{
    int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

    cout << "考试分数为：" << score << endl;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
		if (score > 700)
		{
			cout << "我考上了北大" << endl;
		}
		else if (score > 650)
		{
			cout << "我考上了清华" << endl;
		}
		else
		{
			cout << "我考上了人大" << endl;
		}
		
	}
	else if (score > 500)
	{
		cout << "我考上了二本大学" << endl;
	}
	else if (score > 400)
	{
		cout << "我考上了三本大学" << endl;
	}
	else
	{
		cout << "我未考上本科" << endl;
	}

	system("pause");

	return 0;
}
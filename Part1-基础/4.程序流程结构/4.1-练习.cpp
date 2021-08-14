#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	
	cout << "请分别输入三个数字，判断哪个数最大" << endl;

	cin >> a;
	cin >> b;
	cin >> c;

	cout << "输入的三个数字分别为：\n" << a << '\n' << b << '\n' << c << endl;

	if(a > b)
	{
		if (a > c)
		{
			cout << "a是三个数中最大的" << endl;
		}
		else
		{
			cout << "c是三个数中最大的" << endl;
		}
		
	}
	else
	{
		if (b > c)
		{
			cout << "b是三个数中最大的" << endl;
		}
		else
		{
			cout << "c是三个数中最大的" << endl;
		}
	}
	

	return 0;
}
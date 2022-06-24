// **案例描述：**水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身

// 例如：1^3 + 5^3+ 3^3 = 153

// 请利用do…while语句，求出所有3位数中的水仙花数

#include<iostream>
#include<string>
using namespace std;

int main()
{	
	int num = 100;
	cout << "水仙花数为:" << endl;
	do
	{
		int a = num /100;
		int c = num % 10;
		int mid = num - (100 * a);
		int b = mid / 10;
		if ( (a * a * a) + (b * b * b) + (c * c * c) == num)
		{
			cout << num << endl;
		}
		num++;
	} while (num <= 999);
	
	return 0;
}
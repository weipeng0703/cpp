// 题目
/*
怎么判断一个数是二的倍数，怎么求一个数中有几个1，说一下你的思路并手写代码
*/

// 解答
/*
1、判断一个数是不是二的倍数，即判断该数二进制末位是不是0：
a % 2 == 0 或者a & 0x0001 == 0。


2、求一个数中1的位数，可以直接逐位除十取余判断：
*/

// 1.判断是否为2的倍数

// 直接将int转换为string
#include<string>
using namespace std;


bool panduan(int &a)
{
    string str1 = to_string(a);

    int len = str1.size();

    if (str1[len] == '0')
    {
        return true;
    }

    return false;
    
}

// 2.求数中1的个数

// 法1——同题1一样的思路

int work(int &a)
{
	int num = 0;
	string str = to_string(a);
	for (int i = 0; i < str.size(); i++)
	{
		if(str[i] == '1')
			num++;
	}
	return num;
}

// 法2
int fun(long x)
{
    int _count = 0;
    while(x)
    {
        if(x % 10 == 1)
        ++_count;
        x /= 10;
    }
    return _count;
}


// 知识点
/*

*/
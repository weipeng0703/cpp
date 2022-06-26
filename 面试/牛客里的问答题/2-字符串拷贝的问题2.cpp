// 分析下面代码有什么问题
#include<cstring>
#include<iostream>
using namespace std;

void test() 
{ 
	char string[10], str1[10]; 
	int i; 
	for(i=0; i<10; i++) 
	{ 
		// str1 = 'a'; 
	} 
	strcpy( string, str1 ); 
} 

/*
1.line5-不能用string作为变量名
2.line11-拷贝时最后没有遇到 \0 ,strcpy会从源地址一直往后拷贝，直到遇到'\0'为止。
  所以拷贝的长度是不定的。如果一直没有遇到'\0'导致越界访问非法内存，程序就崩了
3.lin9-数组str1为 char* const类型的右值类型,不能赋值.即使想赋值,也应该是 *str1 = 'a';
*/

// 解决方案
void test2()
{
	char string1[10], str1[10];
	int i;
	for(i=0; i<9; i++)
	{
		str1[i]  = 'a';
	}
	str1[9] = '\0';
	strcpy( string1, str1 );

	cout << str1 << endl;
	cout << string1 << endl;
}

int main()
{
	test2();

	return 0;	
}
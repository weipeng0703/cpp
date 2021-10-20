// 分析下面代码有什么问题
#include<cstring>
void test() 
{ 
    char string[10]; 
    char* str1 = "01234567891"; 
    strcpy( string, str1 ); 
} 


/*
1.line6-在C++不允许const char*的值对char*类型实体化;但在c中是允许这样的初始化方式。
2.line5-C++不允许将变量名声明为string,string是c++的类类型关键字；c中可以，c没有字符串，只有字符数组。
3.line5 6-代码中的str1是11位数字“01234567891”，如果要算上‘\0\',应该是要12字节的字符数组才能准确无误存储；
string这个字符数组只有10字节，导致strcpy后的string内容是0123456789...。
(注)因为在str1中到达字符9后的下一个字符不是’\0‘,strcpy会从源地址一直往后拷贝，直到遇到'\0'为止。
所以拷贝的长度是不定的。如果一直没有遇到'\0'导致越界访问非法内存，程序就崩了
4.line5 6-string应当分配12个字节，因为11个字节中，没有存取到str1中的'\0'，其内容是"01234567891..."而不是"01234567891"，
导致后续如果使用strlen会发生错误，因为strlen的机制是达到'\0'停止
*/

// 其他知识点：
// 1.字符串的长度：空字符串的长度为0，而空格字符串长度为1.虽然输出到屏幕上的内容是一样的，但是ASCII码是不同的。
#include<iostream>
using namespace std;

void test1(){
	char a[] = " ";   
	char b[] = "\0";   

	cout << "字符a的长度为" << strlen(a) << endl;    // 1
	cout << "字符b的长度为" << strlen(b) << endl;    // 0

	char arr[] = "a b";    
	char brr[] = "a\0b";

	cout << "字符数组a为" << arr << endl;    // a b  //长度为 3
	cout << "字符数组b为" << brr << endl;    // a    //长度为1 ，因为遇到'\0'代表结束

}

// 2.strcpy()函数
/*
存储于头文件<cstring>中,位于std库中

功能是把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*
strcpy(a,b)是将b指向的字符串内容复制到a指向的空间中

*/

void test2()
{
	char a[20], c[]="i am a teacher! \0";
	strcpy(a,c);
	cout << "字符串a为" << a << endl;

}

int main()
{
	// test1();

	test2();

	return 0;
}



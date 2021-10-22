// 分析下面代码的问题
#include<iostream>
#include<cstring>
using namespace std;

char *GetMemory( void ) 
{  
 char p[] = "hello world";  
 return p;  
} 

void Test( void ) 
{  
 char *str = NULL;  
 str = GetMemory();  
 printf( str );  
} 

/*
错误：

       char p[]="hello world";相当于char p[12]，strcpy(p,"hello world" ).
       p是一个数组名，属于局部变量，存储在栈中， 
       "hello world" 存储在文字存储区
       数组p中存储的是 "hello world" 的一个副本，当函数结束，p被回收，副本也消失了
       (确切的说p指向的栈存储区被取消标记，可能随时被系统修改)，
       而函数返回的p指向的内容也变得不确定，文字存储区的 "hello world" 未改变。
       
       可以这样修改: 
       ①char* p= " hello world" ; return p; 
       这里p直接指向文字存储区的 " hello world" ，
       函数按值返回p存储的地址，所以有效。 
       ②static char p[]= " hello world" ; return p; 
       static指出数组p为静态数组，函数结束也不会释放，所以有效。 
*/

char* GetMemory1( void ) 
{  
//  char* p = "hello world";         // 解决方案1
 static char p[] = "hello world";    // 解决方案2

 return p;  
} 



void Test1( void ) 
{  
 char *str = NULL;  
 str = GetMemory1();  
 printf( str );  
} 

int main()
{
       Test1();
       return 0;
}
// 分析下面代码的问题
#include<iostream>
#include<cstring>
using namespace std;

void Test( void ) 
{ 
 char *str = (char *) malloc( 100 ); 
 strcpy( str, "hello" ); 
 free( str );  
//  ... //省略的其它语句 
} 

/*
错误：
    1.char *str = (char *) malloc(100)后未进行内存是否申请成功的判断；
    2.在free(str)后未置str为空，导致可能变成一个“野”指针，应加上str = NULL         
*/

// 修改
void Test( void ) 
{ 
 char *str = (char *) malloc( 100 ); 
 if (*str == NULL)
 {
     cout << "申请内存失败" << endl;
 }
 
 
 strcpy( str, "hello" ); 
 free( str );  
 str == NULL;

//  ... //省略的其它语句 
} 
// 分析下面代码的问题
#include<iostream>
#include<cstring>
using namespace std;

void test3(char* str1) 
{ 
       if(str1 == NULL){
              return ;
       }
       char string[10]; 
       if( strlen( str1 ) <= 10 ) 
       { 
              strcpy( string, str1 ); 
       } 
} 

/*
1.line11-不应把string设为变量名
2.line12-对于strlen(str)没有统计最后的\0,
  因为string长度为10，所以str1的长度应该<=10,所以line12应该改为<10
*/

// 考察点：
// strlen(str)：统计字符串字符个数，不包含字符串默认结束符号\0;
// sizeof(str)：统计字符串所占字节数,包含字符串默认结束符号\0;
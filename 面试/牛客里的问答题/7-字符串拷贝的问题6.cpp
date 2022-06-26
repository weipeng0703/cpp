// 分析下面代码的问题
#include<iostream>
#include<cstring>
using namespace std;

void GetMemory( char **p, int num ) 
{ 
 *p = (char *) malloc( num ); 
} 

void Test( void ) 
{ 
 char *str = NULL; 
 GetMemory( &str, 100 ); 
 strcpy( str, "hello" );  
 printf( str );  
} 

/*
错误：
       1.未判断num是否为正
       2.未判断malloc是否成功
       3.没有释放申请的空间 free（str），str= NULL；       
*/

// 修改
void GetMemory1(char **p, int num){
    if(num<=0)
        printf("申请的内存空间要大于零!\n");
    *p = (char*)malloc(num);
    if(*p==NULL)
        printf("申请内存失败!\n");
}

void test1(){
    char *str = NULL;
    GetMemory1(&str, 100);
    strcpy(str, "hello world");
    printf("%s\n", str);
    
//     释放申请的空间
    free(str);
    str = NULL;
}
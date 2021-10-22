// 分析下面代码的问题
#include<iostream>
#include<cstring>
using namespace std;

void GetMemory( char *p ) 
       { 
              p = (char *) malloc( 100 ); 
       } 

void Test( void )  
{ 
       char *str = NULL; 
       GetMemory( str );  
       strcpy( str, "hello world" ); 
       printf( str ); 
} 

/*
test的原目的是为str分配内存（100），以将“hello world”拷贝进去，
但是传入中GetMemory( char *p )函数的形参为字符串指针，在函数内部修改形参并不能真正的改变传入形参的实参值，
执行完line13-14行后str仍然为NULL；

错误：
1：传入形参并不能真正改变形参的值，执行完之后为空；
2：在函数GetMemory中和Test中没有malloc对应的free，会造成内存泄露
           
*/

/*
知识点：
       malloc——向系统申请分配指定size个字节的内存空间，返回类型为void*类型。需强行转换为实际类型的指针。
   例：int *p;  
       p= (int *) malloc ( sizeof (int) ); 
*/

// 修改

void GetMemory1( char **p )
{
   *p = (char *) malloc( 100 );
}
void Test1( void ) 
{
    char *str = NULL;
    GetMemory1( &str ); 
    strcpy( str, "hello world" );
    printf( str );
    free(str);
    str =NULL;
}


int main()
{
    Test1();
    return 0;       

}
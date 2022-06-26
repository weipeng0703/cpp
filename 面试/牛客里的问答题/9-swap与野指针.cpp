// 分析下面代码的问题
#include<iostream>
#include<cstring>
using namespace std;

// swap( int* p1,int* p2 ) 
// { 
//  int *p; 
//  *p = *p1; 
//  *p1 = *p2; 
//  *p2 = *p; 
// } 

/*
错误：
    1.swap函数没有返回值类型
    2.*p未初始化，可能造成野指针       
*/

// 修改
void swap1( int* p1,int* p2 ) 
{ 
 int a = 0;
 int *p = &a;

 *p = *p1; 
 *p1 = *p2; 
 *p2 = *p; 
} 

int main()
{   
    int a = 0, b = 1;

    cout << "a = " << a << " b = " << b << endl;

    swap1(&a, &b);

    
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}
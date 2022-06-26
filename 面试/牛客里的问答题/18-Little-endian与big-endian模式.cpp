// 题目 请写一个C函数，若处理器是Big_endian的，则返回0；若是Little_endian的，则返回1


// 解答
#include<iostream>
using namespace std;

int checkCPU() 
{ 
 { 
 union w 
 {  
 int a; 
 char b; 
 } c; 
 c.a = 1; 
 return (c.b == 1); 
 } 
} 

// 知识点
/*
嵌入式系统开发者应该对Little-endian和Big-endian模式非常了解。
采用Little-endian模式的CPU对操作数的存放方式是从低字节到高字节，
而Big-endian模式对操作数的存放方式是从高字节到低字节
*/
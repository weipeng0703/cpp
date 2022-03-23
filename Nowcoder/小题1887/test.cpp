#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
#include <memory>
using namespace std; 

int n = 14;
double x = 2.71828;
std::string mr = "Mr.String objects!";
show_list(n, x);
//这里的目标是定义show_list()
show_list(x*x, '!', 7, mr);
/*    
运行结果：
    14, 2.71828
    7.38905， !, 7, Mr.String objects!
*/  

/*
 * @Descripttion: My project
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-01-11 20:11:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-28 22:18:31
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
// #include<priority_queue>
#include <memory>

#include <vector>
#include <iostream> 
using namespace std;

#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

#include <stdio.h>

#include <iostream>
#include <Windows.h>
#include <string.h>

#include <iostream>
using namespace std;


template<typename T> int printType(const T& a) ;

template<>
int printType(const int& a) {
    return (typeid(a) == typeid(int))? 1 : 0;
}

int main(){
    int a = printType(1.0);
    if (a == 1) std::cout << "i am int" << std::endl;
    else std::cout << "i am others" << std::endl;
}



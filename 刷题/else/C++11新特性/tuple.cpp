/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-14 10:02:12
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-14 10:03:30
 */
# include<vector> 
# include<algorithm>
# include<unordered_map>
# include<string>
# include<stack>
// # include<priority_queue>
# include<iostream>
# include<thread>
#include<windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
    std::tuple<int, double, string> tuple_1;
    std::tuple<char, short, const char*> tuple_2('x', 2, "hola!");
    tuple_1 = tuple_2;
    return 0; 
}
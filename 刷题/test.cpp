/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 09:17:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-11 21:56:47
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
// #include<priority_queue>
using namespace std;


//考虑内存重叠的memcpy函数
void* memmove(void* dest, void* src, size_t num) {
    assert(dest != NULL) && (src != NULL);
    char* p1 = (char*)dest;
    char* p2 = (char*)src;
    //p1低地址, p2⾼地址
    if(p1 < p2) {
        for(size_t i = 0; i != num; ++i) *(p1++) = *(p2++);
    } else {
        //从后往前赋值
        p1 += num - 1;
        p2 += num - 1;
        for(size_t i = 0; i != num; ++i) *(p1--) = *(p2--);
    }
    return dest;
 }
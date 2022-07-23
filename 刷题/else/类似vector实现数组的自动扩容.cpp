/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 15:54:28
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 19:10:08
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
/*
基本原理
创建一个新的原来大小两倍的数组，将之前的数组数据存入该数组后释放之前的数组指针，
将其指向当前数组

代码实现
1-判断数组的下表使用情况，满了之后创建新的动态数组
2-创建新的动态数组
3-释放之前的内存空间，将原来的数组指针指向新的数组
*/
int main() {
    cout << "输入数组长度" << endl;
    int len;
    cin >> len;
    if(len <= 0) return -1;

    int *array = new int[len];
    int a = 0;
    int i = 0;
    cout << "输入数据存入数组，-1截止" << endl;
    while(cin >> a) {
        if(a == -1) break;
        if(i < len) {
            array[i]=a;
            i++;
            cout<<"继续输入数据，-1截止"<<endl;
        } else {
            // i >= len
            cout << "数组已满，此时长度为： " << i << endl;
            // 1-创建新数组将旧数组数据存入新数组
            int *p = new int[len * 2];
            for(int j = 0; j < len; j++) {
                p[j] = array[j];
            }
            // 2-释放旧数组指针所指的内存空间
            delete[] array;
            // 3-旧指针指向新数组
            array = p;
            array[i] = a;
            i++;
            len = len * 2;
            cout << "现在数组的大小是" << len << ", 可以继续存放新的数据了！" << endl;
            cout << "向新数组继续输入数据，-1截止" << endl;
        }
    } 
    cout << "最终数组的大小是" << len << endl;
    for(int k = 0; k < len; k++) {
       cout << "array[" << k << "] = " << array[k] << endl;
    }
    return 0;
}
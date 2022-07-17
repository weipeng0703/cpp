/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-16 15:40:36
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-16 16:03:44
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
#include<queue>
using namespace std; 

// 希尔排序即为间隔数不同的插入排序
// 通过将⽐较的全部元素分为⼏个区域来提升插⼊排序的性能。这样可以让⼀个元素可以⼀次性地朝最终位置前进⼀⼤步。
// 然后算法再取越来越⼩的步⻓进⾏排序，算法的最后⼀步就是普通的插⼊排序(间隔为1)，但是到了这步，需排序的数据⼏乎是已排好的了。
void shellSort(vector<int>& nums) {
    for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < nums.size(); i++) {
            for (int j = i; j - gap >= 0 && nums[j - gap] > nums[j]; j -= gap) {
                std::swap(nums[j - gap], nums[j]);
            }
        }
    }
}
int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';

    shellSort(a);
    cout << endl;
    cout << "希尔排序完成" << endl;
    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }
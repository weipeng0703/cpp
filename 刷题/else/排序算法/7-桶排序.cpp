/*
 * @Descripttion: 
 * @version: 1.00
 * @Author: weipeng
 * @Date: 2022-07-16 15:02:47
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-16 15:39:39
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

// 将数组分到有限数量的桶⾥。每个桶再个别排序（有可能再使⽤别的排序算法或是以递归⽅式继续使⽤桶排序进⾏排序）。
void bucketSort(vector<int>& nums) {
    if (nums.empty()) return;
    int low = nums[0], high = nums[0];
    // int low = *std::min_element(nums.begin(), nums.end());
    // int high = *std::max_element(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        low = min(low, nums[i]);
        high = max(high, nums[i]);
    }
    int n = high - low + 1;
    std::vector<int> buckets(n);
    std::vector<int> res;
    // 映射函数将数据映射到桶里
    for (auto ele : nums) ++buckets[ele - low];
    // 对每个桶里的数据进行排序
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            res.push_back(i + low);
        }
    }
    for (int i = 0; i < nums.size(); i++) nums[i] = res[i];
}
int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';

    bucketSort(a);
    cout << endl;
    cout << "桶排序完成" << endl;
    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }
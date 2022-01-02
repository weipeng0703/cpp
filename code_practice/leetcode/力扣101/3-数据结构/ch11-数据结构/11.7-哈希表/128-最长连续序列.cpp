/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：

    输入：nums = [100,4,200,1,3,2]
    输出：4
    解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

    输入：nums = [0,3,7,2,5,8,4,6,0,1]
    输出：9
*/

#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 方法一：暴力遍历——将数组排序，然后记录长度，但是该方法时间复杂度为O(nlogn)不满足要求

// 方法二：哈希集合
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 建立一个存储所有数的哈希表，同时起到去重功能
        unordered_set<int> hash;
        for(auto x : nums) 
            hash.insert(x);
        
        int res = 0;
        // 遍历经过去重后的数组
        for(auto x : hash)
        {
            // 只有当num-1不存在时，才开始向后遍历num+1，num+2，num+3......
            if(!hash.count(x-1))
            {
                int y = x;   //以当前数x向后枚举
                // 依次枚举连续递增的数字，直到没有连续递增的数字
                while(hash.count(y + 1)) 
                    y++;
                // 计算长度，更新答案
                res = max(res, y - x + 1);  
            }
        }
        return res;
    }
};

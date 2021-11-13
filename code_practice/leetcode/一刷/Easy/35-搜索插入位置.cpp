/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

示例 1:
    输入: nums = [1,3,5,6], target = 5
    输出: 2
示例 2:
    输入: nums = [1,3,5,6], target = 2
    输出: 1
示例 3:
    输入: nums = [1,3,5,6], target = 7
    输出: 4
示例 4:
    输入: nums = [1,3,5,6], target = 0
    输出: 0
示例 5:
    输入: nums = [1], target = 0
    输出: 0

*/

#include<vector>
using namespace std;

// 通用方法——顺序数组用二分查找，时间复杂度为log(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right)
        {
            int mid = left + (right - 1) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            right = mid - 1;
            
        }
        return left;
    }
};



// 简单方法
//  find()、find_if()、search()函数的底层实现都采用的是顺序查找（逐个遍历）的方式，
//  在某些场景中的执行效率并不高，例如当指定区域内的数据处于有序状态时，
//  如果想查找某个目标元素，更推荐使用二分查找的方法（相比顺序查找，二分查找的执行效率更高）。

// C++ STL标准库中还提供有 lower_bound()、upper_bound()、equal_range() 
// 以及 binary_search() 这 4 个查找函数，
// 它们的底层实现采用的都是二分查找的方式。

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        // lower_bound()返回范围内大于等于target的第一个数的地址
        // lower_bound()返回范围内严格大于target的第一个数的地址
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};

// 注：含力扣153与154题，剑指offer中是154题
/*
LC-154
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。
请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为1。  

示例 1：
    输入：[3,4,5,1,2]
    输出：1
示例 2：
    输入：[2,2,2,0,1]
    输出：0
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
using namespace std; 
// 1.直接sort
class Solution {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
};
// 2.暴力查找
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int temp = numbers[0];
        for (auto num : numbers)
        {
            if (num < temp)
            {
                temp = num;
            }
            
        }
        return temp;
    }
};
// 3.最佳复杂度方法——二分查找
// 排序数组的查找问题首先考虑使用 二分法 解决，其可将 遍历 的 线性级别 时间复杂度降低至 对数级别 
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        // 使待二分查找的区间恢复二段性
        while (left < right && numbers[left] == numbers[right])
        {
            right--;
        }
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else if (numbers[mid] < numbers[right])
            {
                right = mid;
            }
            else
            {
                right--;
            }
        }
        return numbers[left];
    }
};
// 时间复杂度：平均时间复杂度为 O(logn)，其中 n 是数组的长度。
// 如果数组是随机生成的，那么数组中包含相同元素的概率很低，在二分查找的过程中，大部分情况都会忽略一半的区间。
// 而在最坏情况下，如果数组中的元素完全相同，那么 while 循环就需要执行 n 次，每次忽略区间的右端点，时间复杂度为 O(n)。
// 空间复杂度：O(1),不需要使用额外辅助空间

/*
LC-153
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。
例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。
请你找出并返回数组中的 最小元素 。

示例 1：
    输入：nums = [3,4,5,1,2]
    输出：1
    解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
示例 2：
    输入：nums = [4,5,6,7,0,1,2]
    输出：0
    解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
*/ 
// 方法1：直接sort()
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
// 方法2：二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] < nums[j])
            {
                j = mid;
            }
            else if (nums[mid] > nums[j])
            {
                i = mid + 1;
            }
            else
            {
                j--;
            }
        }
        return nums[i];
    }
};
/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。
例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，
并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

示例 1：

输入：nums = [1,3,5]
输出：1

示例 2：

输入：nums = [2,2,2,0,1]
输出：0

*/
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;


// 第一思路：直接排序求数组中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return -1;
        }
        sort(nums.begin(), nums.end());

        return nums[0];
    }
};

// 二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[high]) {
                high = mid;
            }
            else if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = high - 1;
            }
        }
        return nums[low];
    }
};

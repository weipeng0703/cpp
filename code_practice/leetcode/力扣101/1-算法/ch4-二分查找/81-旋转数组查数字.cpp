/*
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。
如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

示例 1：

输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true

示例 2：

输入：nums = [2,5,6,0,0,1,2], target = 3
输出：false
*/
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;


// 第一思路：一个循环暴力解法
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
        {
            return false;
        }
        else if (size == 1 && nums[0] == target)
        {
            return true;
        }
        
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] == target)
            {
                return true;
            }
            
        }
        return false;
    }
};


// 第二思路：先使用sort进行排序，之后进行二分查找
// 但是一直没ac，发现忽略掉了一个问题：二分查找对于重复元素需要进行去重处理

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;

        while (left <= right)
        {
            mid = left + (right - left)/2;

            if (nums[mid] == target)
            {
                return true;
            }
            // 无法判断哪个区间是增序的
            if (nums[left] == nums[mid])
            {
                // 如果中点和左端的数字相同，我们并不能确定是左区间全部相同，还是右区间完全相同。
                // 在这种情况下，我们可以简单地将左端点右移一位，然后继续进行二分查找
                ++left;
            }
            else if (nums[mid] <= nums[right])
            {
                // 右区间增序
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }  
            }
            else
            {
                // 左区间增序
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
                
            }              
        }
        return false;
          
    }
};
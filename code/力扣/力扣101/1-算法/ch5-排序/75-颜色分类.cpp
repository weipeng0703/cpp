/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。


示例 1：

    输入：nums = [2,0,2,1,1,0]
    输出：[0,0,1,1,2,2]

示例 2：

    输入：nums = [2,0,1]
    输出：[0,1,2]

示例 3：

    输入：nums = [0]
    输出：[0]

示例 4：

    输入：nums = [1]
    输出：[1]

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:直接sort()排序 时间复杂度O(nlogn)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

// 方法二:单指针
// 两次遍历nums，第一次将所有的0置于最前，第二次将所有的1放在0后
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int ptr = 0;
        // 第一次遍历，将所有0放到ptr前面
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
            
        }
        // 第二次遍历，将所有1排序完毕
        for (int i = ptr; i < size; i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        
    }
};

// 方法3:双指针
// 分别用两个指针交换0和1，或者用两个指针交换0和2，方法类似
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int size = nums.size();
       int p0 = 0, p1 = 0;

       for (int i = 0; i < size; i++)
       {
           if (nums[i] == 1)
           {
               swap(nums[i], nums[p1]);
               ++p1;
           }
           else if (nums[i] == 0)
           {
               swap(nums[i], nums[p0]);
            //    因为p1之前的都是已经排好序后的1，所以p0当前指向的是1，
            //    将nums[i], nums[p0]交换后有可能将已经排好序后的1换出去了，所以需要将它与nums[p1]交换再换进来
               if (p0 < p1)
               {
                   swap(nums[i], nums[p1]);
               }   
               ++p0;
               ++p1;
           }
       }
    }
};
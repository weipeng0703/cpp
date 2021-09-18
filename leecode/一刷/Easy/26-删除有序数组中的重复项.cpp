/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。

要求：不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

// 双指针法
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // 对于有元素的数组，因为不管怎么删总会有一个元素在数组里面，所以指针从数组中第二个元素开始
        // 定义双指针,fast表示数组下标，slow表示下一个不同元素在数组中应该处于的位置（下标）
        int fast = 1, slow = 1;

        while (fast < nums.size()) {   // fast 遍历数组
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;   // 此处跟下面改为++在后也可以都通过测试案例
            }
            ++fast;
        }
        return slow;
    }
};


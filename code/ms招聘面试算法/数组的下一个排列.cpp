/*
力扣T31. 下一个排列
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 两遍扫描
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] > nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= i && nums[i] <= nums[j])
            {
                j--;
            }
        }
        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
    }
};
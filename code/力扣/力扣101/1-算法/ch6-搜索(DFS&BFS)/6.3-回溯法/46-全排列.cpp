/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：
    输入：nums = [0,1]
    输出：[[0,1],[1,0]]
示例 3：
    输入：nums = [1]
    输出：[[1]]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.回溯法
/*
回溯法大框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        if (size == 0)
        {
            return ans;
        }
        backtrack(nums, 0, ans);
        return ans;
    }

    void backtrack(vector<int>& nums, int level, vector<vector<int>>& ans)
    {
        if (level == nums.size() - 1)
        {
            // 终止条件，到最后一个数字，没法再交换了
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++)
        {
            // 当前数字要跟之后所有数字交换一遍（包括自己）
            swap(nums[i], nums[level]);     // 修改当前节点状态

            // 递归，数组[0, index]现在已经排列完成, 从index + 1开始排列后面的数组
            // 后面的元素进行交换
            backtrack(nums, level + 1, ans);// 递归子节点

            // 还原回来
            // 这个地方的原理是：因为前面swap了，所以上面的回溯是基于之前swap的操作（即1和1交换）
            // 现在将之前swap后的两个数交换回来，返回初始状态进行回溯（即1和2交换）
            swap(nums[i], nums[level]);     // 回正当前节点状态
        }     
    }
};
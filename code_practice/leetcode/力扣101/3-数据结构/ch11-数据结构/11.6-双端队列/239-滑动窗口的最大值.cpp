/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

示例一：
    输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
    输出：[3,3,5,5,6,7]
    解释：
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7        3
    1  3 [-1  -3  5] 3  6  7        5
    1  3  -1 [-3  5  3] 6  7        5
    1  3  -1  -3 [5  3  6] 7        6
    1  3  -1  -3  5 [3  6  7]       7
示例 2：
    输入：nums = [1], k = 1
    输出：[1]
示例 3：
    输入：nums = [1,-1], k = 1
    输出：[1,-1]
示例 4：
    输入：nums = [4,-2], k = 2
    输出：[4]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 方法一：暴力遍历法
// 自己写的遍历，会超时
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res;
        for (int i = 0; i <= size - k; i++)
        {
            vector<int> temp;
            for (int j = i; j < i + k; i++)
            {
                temp.push_back(j)
            }
            sort(temp.begin(), temp.end());
            int size1 = temp.size();
            res.push_back(temp[size1 - 1]);
        }
        return res;
    }
};
// 用max的方法暴力遍历
// 伪代码
for(size_t i=0;i<nums.size();i++){
    int maxValue=INT_MIN;
    for(size_t j=i;j<i+k;j++){
        maxValue=max(maxValue,nums[j]);
    }
    res.push_back(maxValue);
}

// 方法二：双端队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;  
        deque<int> que;   

        // 遍历数组中元素，right表示滑动窗口右边界
        for(int right=0; right < nums.size(); right++){
            // 如果队列不为空且当前考察元素大于等于队尾元素，则将队尾元素移除。
            // 直到，队列为空或当前考察元素小于新的队尾元素
            while(!que.empty()&&nums[que.back()]<=nums[right]){
                que.pop_back();
            }
            // 存储元素下标
            que.push_back(right);

            // 计算窗口左侧边界
            int left = right - k + 1;

            // 当队首元素的下标小于滑动窗口左侧边界left时
            // 表示队首元素已经不再滑动窗口内，因此将其从队首移除
            while(que.front() < left){
                que.pop_front();
            }

            // 由于数组下标从0开始，因此当窗口右边界right+1大于等于窗口大小k时意味着窗口形成。
            // 此时，队首元素就是该窗口内的最大值
            if(right + 1 >= k){
                ans.push_back(nums[que.front()]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> que;

        // right表示滑动窗口的右值
        for (int right = 0; right < nums.size(); right++)
        {
            while (!que.empty() && nums[right] >= nums[que.back()])
            {
                que.pop_back();
            }
            que.push_back(right);

            int left = right - k + 1;
            while (que.front() < left)
            {
                que.pop_front();
            }
            if (right + 1 >= k)
            {
                res.push_back(nums[que.front()]);
            }
            
        }
        return res;
    }
};
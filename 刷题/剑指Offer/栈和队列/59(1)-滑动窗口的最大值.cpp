/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:
    输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
    输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

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
#include<priority_queue>
using namespace std; 

// 1.暴力遍历(超时)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0)
        {
            return ans;
        }
        if (k == 1)
        {
            return nums;
        }
        if (nums.size() <= k)
        {
            sort(nums.begin(), nums.end());
            return vector<int>{nums[nums.size() - 1]};
        }
        
        for (int i = 0, j = i + k - 1; j < nums.size(); i++)
        {
            int maxNum = 0;
            for (int k = i; k <= j; k++)
            {
                maxNum = max(maxNum, nums[k]);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};
// 2.优先队列
/*
普通的队列是一种先进先出的数据结构，元素在队列尾追加，而从队列头删除。

在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。
优先队列具有最高级先出 （first in, largest out）的行为特征。
对于优先队列中 pair 的比较，先比较第一个元素，第一个相等比较第二个。

优先队列具有队列的所有特性，包括队列的基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。

和队列相同的基本操作:
    top 访问队头元素
    empty 队列是否为空
    size 返回队列内元素个数
    push 插入元素到队尾 (并排序)
    emplace 原地构造一个元素并插入队列
    pop 弹出队头元素
    swap 交换内容
*/
lass Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0)
        {
            return ans;
        }
        if (k == 1)
        {
            return nums;
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++)
        {
            q.emplace(nums[i], i);
        }
        // 第一个滑动窗口中的最大值
        ans.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)，优先队列


// 3.单调双端队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> que;
        // right表示滑动窗口的右值
        for (int right = 0; right < nums.size(); right++){
            // 当前的nums[right]为此时滑动窗口的最大值
            while (!que.empty() && nums[right] >= nums[que.back()]){
                que.pop_back();
            }
            que.push_back(right);
            // 将当前不在滑动窗口中的元素从队列中删除
            int left = right - k + 1;
            while (que.front() < left){
                que.pop_front();
            }
            // 由于数组下标从0开始，因此当窗口右边界right+1大于等于窗口大小k时，意味着窗口形成。
            // 此时，队首元素就是该窗口内的最大值。
            if (right + 1 >= k){
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }
};
// 时间复杂度：O(N)，遍历数列中每个元素
// 空间复杂度：O(k)，需要额外的队列，其使用空间不会超过k
/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。
示例 1：
    输入：n = 4, k = 2
    输出：
    [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
    ]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.回溯法
// 类似于排列问题，也可以进行回溯。
// 排列回溯的是交换的位置，而组合回溯的是是否把当前的数字加入结果中。
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
private:
    // 用全局变量表示，回溯时就不用担心引用和局部变量的问题了，也可以少写几个参数了
    vector<vector<int>> res_s;
    vector<int> res;

    // 回溯
    backtrack(int n, int k, int flag)
    {
        if (res.size() == k)
        {
            res_s.push_back(res);
            return;
        }
        // 注意这个地方可以采用剪枝处理
        // 例如n = 4，k = 4的话，那么第一层for循环的时候，从元素2开始的遍历都没有意义了。 
        // 在第二层for循环，从元素3开始的遍历都没有意义了。
        // 优化过程写在下面
        for (int i = flag; i <= n; i++)
        {
            // 从[1, n]内的1开始处理节点
            res.push_back(i);
            // 递归处理[2, n]
            backtrack(n, k, i + 1);
            // 处理完1打头的之后将1退出来，开始处理2打头的
            res.pop_back();
        }
    }
public:
    // 注意[1, n]是连续的n个数
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res_s;
        vector<int> res;
        backtrack(n, k, 1);
        return res_s;
    }
};

// 2.剪枝优化

// 优化过程如下：
// 1.已经选择的元素个数：path.size();
// 2.还需要的元素个数为: k - path.size();
// 3.在集合n中至多要从该起始位置 : n - (k - path.size()) + 1，开始遍历
// 为什么有个+1呢，因为包括起始位置，我们要是一个左闭的集合。
// 举个例子，n = 4，k = 3， 目前已经选取的元素为0（path.size为0），n - (k - 0) + 1 即 4 - ( 3 - 0) + 1 = 2。
// 从2开始搜索都是合理的，可以是组合[2, 3, 4]。
// 这里想不懂的话，可以举一个例子，就知道是不是要+1了。

class Solution {
private:
    // 用全局变量表示，回溯时就不用担心引用和局部变量的问题了，也可以少写几个参数了
    vector<vector<int>> res_s;
    vector<int> res;

    // 回溯
    void backtrack(int n, int k, int flag)
    {
        if (res.size() == k)
        {
            res_s.push_back(res);
            return;
        }
        // 注意这个地方可以采用剪枝处理
        // 例如n = 4，k = 4的话，那么第一层for循环的时候，从元素2开始的遍历都没有意义了。 
        // 在第二层for循环，从元素3开始的遍历都没有意义了。
        // 优化过程写在下面
        for (int i = flag; i <= (n - (k - res.size()) + 1); i++)
        {
            // 从[1, n]内的1开始处理节点
            res.push_back(i);
            // 递归处理[2, n]
            backtrack(n, k, i + 1);
            // 处理完1打头的之后将1退出来，开始处理2打头的
            res.pop_back();
        }
    }
public:
    // 注意[1, n]是连续的n个数
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return res_s;
    }
};

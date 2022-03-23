/*
同力扣T946. 判断栈的压入和弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

示例 1：
    输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    输出：true
    解释：我们可以按以下顺序执行：
    push(1), push(2), push(3), push(4), pop() -> 4,
    push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2:
    输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    输出：false
    解释：1 不能在 2 之前弹出。
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
// #include<unordered_map>
using namespace std; 

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()){
            return false;
        }
        // 辅助栈
        stack<int> st;
        int j = 0;
        for (const auto& ele : pushed)
        {
            st.push(ele);
            // st.top() == popped[j]判断辅助栈的栈顶元素是否跟popped对应位置相同,相同则弹出,
            // j++判断popped中下一个位置是否与栈顶元素相同
            while (!st.empty() && j < popped.size() && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        // 如果可以按照popped序列弹出,那么j应该等于popped大小,因为每一次弹出操作时j都会++
        return j == popped.size();
    }
};
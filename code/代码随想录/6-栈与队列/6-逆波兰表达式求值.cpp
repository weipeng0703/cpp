/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-10 10:47:24
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-10 11:06:46
 */
/*
力扣150. 逆波兰表达式求值
根据 逆波兰表示法，求表达式的值。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
注意 两个整数之间的除法只保留整数部分。
可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：
    输入：tokens = ["2","1","+","3","*"]
    输出：9
    解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：
    输入：tokens = ["4","13","5","/","+"]
    输出：6
    解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
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

// 1.分情况讨论
// 注意stoi()函数的应用，将string转为int
// 对于 减法和除法，都是用 栈内的数字 -或/ 栈顶数字
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string ele : tokens) {
            if (ele == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = a + b;
                st.push(temp);
            } else if (ele == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = b - a;
                st.push(temp);
            } else if (ele == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = a * b;
                st.push(temp);
            } else if (ele == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = b / a;
                st.push(temp);
            } else st.push(stoi(ele));
        }
        return st.top();
    }
};
// 2.代码写法优化
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string ele : tokens) {
            if (ele == "+" || ele == "-" || ele == "*" || ele == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int temp = 0;
                if (ele == "+") temp = b + a;
                if (ele == "-") temp = b - a;
                if (ele == "*") temp = b * a;
                if (ele == "/") temp = b / a;
                st.push(temp);
            } else st.push(stoi(ele));
        }
        return st.top();
    }
};
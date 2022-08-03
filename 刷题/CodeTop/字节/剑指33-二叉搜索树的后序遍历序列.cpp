/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-08-01 20:02:16
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-01 20:39:57
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
#include<queue>
using namespace std; 
/*
力扣-剑指 Offer 33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
示例 1：
    输入: [1,6,3,2,5]
    输出: false
示例 2：
    输入: [1,3,2,6,5]
    输出: true
*/ 

// 1-从后向前递归加分治
class Solution {
public:
    bool recurr(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int i;
        // 寻找到左分支(均比中间节点小)
        for (i = right; i >= left; i--) {
            if (postorder[i] < postorder[right]) break;
        }
        // 左分支内如果有 > postorder[right]的数则false
        for (int j = i; j >= left; j--) {
            if (postorder[j] > postorder[right]) return false;
        }
        return recurr(postorder, left, i) && recurr (postorder, i + 1, right - 1);
        
    }
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0) return true;
        return recurr(postorder, 0, postorder.size() - 1);
    }
};

// 2-从前向后递归加分治
class Solution {
public:
    bool recurr(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int p = left, temp = 0;
        while (postorder[p] < postorder[right]) p++;
        // 记录左分支的位置
        temp = p - 1;
        while (postorder[p] > postorder[right]) p++;
        return p == right && recurr(postorder, left, temp) && recurr(postorder, temp + 1, right - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0) return true;
        return recurr(postorder, 0, postorder.size() - 1);
    }
};

// 完整程序
# include<iostream>
bool recurr(vector<int>& postorder, int left, int right) {
    if (left >= right) return true;
    int i;
    // 寻找到左分支(均比中间节点小)
    for (i = right; i >= left; i--) {
        if (postorder[i] < postorder[right]) break;
    }
    // 左分支内如果有 > postorder[right]的数则false
    for (int j = i; j >= left; j--) {
        if (postorder[j] > postorder[right]) return false;
    }
    return recurr(postorder, left, i) && recurr (postorder, i + 1, right - 1);
}
bool verifyPostorder(vector<int>& postorder) {
    if (postorder.size() == 0) return true;
    return recurr(postorder, 0, postorder.size() - 1);
}
int main() {
    int n;
    cout << "请输入数组大小：" << endl;
    cin >> n;
    vector<int> test(n);
    cout << "请按顺序输入数组元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> test[i];
    }
    if (verifyPostorder(test) == true) cout << "是后序序列" << endl;
    else cout << "不是后序序列" << endl;

    return 0;
}
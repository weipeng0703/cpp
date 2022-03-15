/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
参考以下这颗二叉搜索树：
     5
    / \
   2   6
  / \
 1   3
示例 1：
    输入: [1,6,3,2,5]
    输出: false
示例 2：
    输入: [1,3,2,6,5]
    输出: true
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
using namespace std; 

// 1.从后向前递归分治
class Solution {
public:
    bool recurr(vector<int>& postorder, int left, int right){
        if (left >= right)
        {
            return true;
        }
        int i;
        for (i = left; i <= right; i++)
        {
            if (postorder[i] > postorder[right])
            {
                break;
            }
        }
        for (int j = i; j <= right; j--)
        {
            if (postorder[j] < postorder[right])
            {
                return false;
            }
        }
        return recurr(postorder, left, i) && recurr(postorder, i + 1, right - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0)
        {
            return false;
        }
        return recurr(postorder, 0, postorder.size() - 1);
    }
};
// 2.从前向后递归分治
class Solution {
public:
    bool helpe(vector<int> &postorder, int l, int r) {
        if (l >= r) return true;
        int p = l, m = 0;
        while (postorder[p] < postorder[r]) ++p;
        // 切割点
        m = p; 
        while (postorder[p] > postorder[r]) ++p;
        // 判断到p是否移动到最后 && 左子树是否符合要求 && 右子树是否符合要求
        return p == r && helpe(postorder, l, m - 1) &&
            helpe(postorder, m, r - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return helpe(postorder, 0, postorder.size() - 1);
    }
};

// 3.单调栈
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/2chong-jie-fa-qing-xi-luo-ji-miao-dong-o-23nq/

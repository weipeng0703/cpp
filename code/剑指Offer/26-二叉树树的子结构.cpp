/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
示例 1:
    输入：A = [1,2,3], B = [3,1]
    输出：false
示例 2：
    输入：A = [3,4,5,1,2], B = [4,1]
    输出：true
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归（该题类似于对树A进行先序遍历）
class Solution {
public:
    bool iscontainer(TreeNode* A, TreeNode* B)
    {
        // 若B走完了,说明查找完毕,B为A的子结构
        if (B == nullptr)
        {
            return true;
        }
        // 若B不为空并且A为空或者A与B的值不相等,直接可以判断B不是A的子结构
        if (A == nullptr || A->val != B->val)
        {
            return false;
        }
        // 当A与B当前节点值相等,若要判断B为A的子结构,
        // 还需要判断B的左子树是否为A左子树的子结构 && B的右子树是否为A右子树的子结构
        // 若两者都满足就说明B是A的子结构,并且该子结构以A根节点为起点
        return iscontainer(A->left, B->left) && iscontainer(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
        {
            return false;
        }
        return iscontainer(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);;
    }
};
// 时间复杂度:O(MN),M N分别为树A B的节点数
// 空间复杂度:O(M)

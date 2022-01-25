/*
给你二叉搜索树的根节点 root ，
该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。

示例一：
    输入：root = [1,3,null,null,2]
    输出：[3,1,null,null,2]
    解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 1.显式进行中序遍历
// 对原树进行中序遍历结果保存在一个数组中，遍历该数组找到出错位置后调换两个位置即可
class Solution {
public:
    // 中序遍历
    // 注意这里数组要使用引用形式，改变数组
    void in_order(TreeNode* root, vector<TreeNode*>& temp)
    {
        if (root == nullptr)
        {
            return;
        }
        in_order(root->left, temp);
        temp.push_back(root);
        in_order(root->right, temp);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> temp;
        in_order(root, temp);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        for (int i = 0; i < temp.size() - 1; i++)
        {
            if (temp[i]->val > temp[i + 1]->val)
            {
                second = temp[i + 1];
                if (first == nullptr)
                {
                    first = temp[i];
                }
                
            }
            
        }
        int mid = second->val;
        second->val = first->val;
        first->val = mid;
    }
};

// 2.用一个指针记录前面的数字即可
class Solution {
public:
    TreeNode *fir = nullptr;
    TreeNode *sec = nullptr;
    TreeNode *pre = nullptr;

    void dfs(TreeNode *root) {
        // 递归结束的条件
        if (!root)
            return;
        // 中序遍历：左
        dfs(root->left);
        // 中序遍历：中
        if (pre != nullptr) {
            if (fir == nullptr && pre->val >= root->val) fir = pre;
            if (fir != nullptr && pre->val >= root->val) sec = root;
        }
        pre = root;
        // 中序遍历：右
        dfs(root->right);
    }

    void recoverTree(TreeNode *root) {
        dfs(root);
        int tmp = fir->val;
        fir->val = sec->val;
        sec->val = tmp;

    }
};
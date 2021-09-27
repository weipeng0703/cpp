/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。
*/

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
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1.递归实现
class Solution {
public:
    bool check(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }
        else if (!p || !q)
        {
            return false;
        }
        else
        {
            return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
        }
        
        
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

// 2.迭代实现
// 「方法一」中我们用递归的方法实现了对称性的判断，那么如何用迭代的方法实现呢？
// 首先我们引入一个 队列 ——这是把递归程序改写成迭代程序的常用方法。
// 初始化时我们把根节点入队两次。
// 每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），
// 然后将两个结点的左右子结点按相反的顺序插入队列中。eg.321123是对称的，321321不对称
// 当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。
#include<queue>
using namespace std;

class Solution
{
    bool check(TreeNode *u, TreeNode *v)
    {
        queue<TreeNode*> que;
        que.push(u);
        que.push(v);

        while (!que.empty())
        {
            u = que.front();
            que.pop();
            v = que.front();
            que.pop();

            if (!u && !v)
            {
                continue;
            }

            if ((!u || !v) || (u->val != v -> val))
            {
                return false;
            }
            que.push(u->left);
            que.push(v->right);

            que.push(u->right);
            que.push(v->left);

        }
        return true;        
    }



    bool isSymetric(TreeNode* root)
    {
        return check(root, root);
    }
};

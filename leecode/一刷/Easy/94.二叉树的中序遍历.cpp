/*
给定一个二叉树的根节点 root ，返回它的 中序 遍历。

中序遍历：中序遍历（LDR）是二叉树遍历的一种，也叫做中根遍历、中序周游。
    在二叉树中，中序遍历首先遍历左子树，然后访问根结点，最后遍历右子树。
    画图直观来看，二叉树的中序遍历就是将节点投影到一条水平的坐标上

方法：
    1.递归法：递归的终止条件是当前节点是否为空。首先递归调用遍历左子树，然后访问当前节点，最后递归调用右子树
        递归实现时，是函数自己调用自己，一层层的嵌套下去，操作系统/虚拟机自动帮我们用 栈 来保存了每个调用的函数
    2.迭代法：使用栈(自己模拟上述递归的调用过程)：
        从根节点开始找二叉树的最左节点，将走过的节点保存在一个栈中，找到最左节点后访问，
        对于每个节点来说，它都是以自己为根的子树的根节点，访问完之后就可以转到右儿子上了。
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
#include<vector>
#include<TreeNode>
using namespace std; 

// 1.递归法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        inorderHelper(ret, root);
        return ret;

    }
private:
    inorderHelper(vector<int> & nums, TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        inorderHelper(ret, root->left);
        ret.push_back(root->val);
        inorderHelper(ret, root->right);
    }
};

// 2.迭代法
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL)
        {
            return ret;
        }
        TreeNode *curr = root;
        stack<TreeNode*> st;
        while (root != NULL || !st.empty())
        {
            while (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ret.push_back(root->val);
            root = root->right;
        }
        return ret;

        
    }
};
/*
同力扣T297
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例 1:
    输入：root = [1,2,3,null,null,4,5]
    输出：[1,2,3,null,null,4,5]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sstream>
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
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
        {
            return "#";
        }
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    TreeNode* Temp(istringstream& ss){
        string temp;
        ss >> temp;
        if (temp == "#")
        {
            return nullptr;
        }
        // stoi()将string字符串转换为int类型
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = Temp(ss);
        root->right = Temp(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return Temp(ss);
    }
};
// C++引入了ostringstream、istringstream、stringstream这三个类，要使用他们创建对象就必须包含<sstream>头文件。

// istringstream类用于执行C++风格的串流的 输入 操作。

// ostringstream类用于执行C风格的串流的 输出 操作。

// strstream类同时可以支持C风格的串流的 输入输出 操作。

// istringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来。


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
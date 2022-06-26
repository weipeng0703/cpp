// 题目
/*
实现二叉树的二叉树序列化反序列化
*/

// 解答
/*

> 序列化：必须保存一个中序遍历结果，然后外加一个前序或者后序遍历结果
>反序列化：根据两次遍历生成的结果恢复二叉树，代码如下(前序和中序)

TreeNode* helper(vector<int>pre,int startPre,int endPre,vector<int>in,int startIn,int endIn)
{
    if(startPre>endPre||startIn>endIn)
        return nullptr;
    TreeNode * root=new TreeNode(pre[startPre]);
    for(int i=startIn;i<=endIn;++i)
    {
        if(in[i]==pre[startPre])
        {
            root->left=helper(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
            root->right=helper(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
            break;
        }
    }
    return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
{
    TreeNode *root=helper(pre,0,pre.size()-1,vin,0,vin.size()-1);
    return root;
}

*/


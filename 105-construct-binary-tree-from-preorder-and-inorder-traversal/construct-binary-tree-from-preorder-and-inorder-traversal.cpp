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
 #include <algorithm>
class Solution {
public:

    TreeNode* uniqueTree(vector<int>& preorder, vector<int>& inorder,int start,int end,int &i){
        if(start>end)   return nullptr;
        if(preorder.size()==i)  return nullptr;
        TreeNode*root=new TreeNode(preorder[i]);
        int rootIdx=find(inorder.begin(),inorder.end(),root->val)-inorder.begin();
        i++;
        TreeNode* left=uniqueTree(preorder,inorder,start,rootIdx-1,i);
        TreeNode* right=uniqueTree(preorder,inorder,rootIdx+1,end,i);

        root->left=left;
        root->right=right;
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        return uniqueTree(preorder,inorder,0,preorder.size()-1,i);

    }
};
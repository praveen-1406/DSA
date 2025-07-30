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

    // TreeNode* uniqueTree(vector<int>& preorder, vector<int>& inorder,int start,int end,int &i){
    //     if(start>end)   return nullptr;
    //     if(preorder.size()==i)  return nullptr;
    //     TreeNode*root=new TreeNode(preorder[i]);
    //     int rootIdx=find(inorder.begin(),inorder.end(),root->val)-inorder.begin();
    //     i++;
    //     TreeNode* left=uniqueTree(preorder,inorder,start,rootIdx-1,i);
    //     TreeNode* right=uniqueTree(preorder,inorder,rootIdx+1,end,i);

    //     root->left=left;
    //     root->right=right;
    //     return root;
    // }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // int i=0;
        // return uniqueTree(preorder,inorder,0,preorder.size()-1,i);

        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)   mp[inorder[i]]=i;

        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);

    }
    TreeNode* buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,unordered_map<int,int>&mp){
        if(preStart>preEnd || inStart>inEnd)    return nullptr;

        TreeNode*root=new TreeNode(preorder[preStart]);
        int rootIdx=mp[root->val];
        int remElem=rootIdx-inStart;

        root->left=buildTree(preorder,preStart+1,preStart+remElem,inorder,inStart,rootIdx-1,mp);
        root->right=buildTree(preorder,preStart+remElem+1,preEnd,inorder,rootIdx+1,inEnd,mp);

        return root;
    }
};
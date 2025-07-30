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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)   mp[inorder[i]]=i;

        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }

    TreeNode* buildTree(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd,unordered_map<int,int>&mp){
        if(inStart>inEnd || postStart>postEnd)  return nullptr;

        TreeNode*root=new TreeNode(postorder[postEnd]);
        int rootIdx=mp[root->val];
        int remElem=rootIdx-inStart;

        root->left=buildTree(inorder,inStart,rootIdx-1,postorder,postStart,postStart+remElem-1,mp);
        root->right=buildTree(inorder,rootIdx+1,inEnd,postorder,postStart+remElem,postEnd-1,mp);

        return root;
    }
};
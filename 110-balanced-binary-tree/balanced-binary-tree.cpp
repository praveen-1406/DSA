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
    int f(TreeNode* node){
        if(node==nullptr)   return 0;
        int left=f(node->left);
        int right=f(node->right);
        if(left<0 || right<0)   return -1;
        if(abs(left-right)<=1)  return 1+max(left,right);
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans=f(root);
        if(ans<0)   return false;
        return true;
    }
};
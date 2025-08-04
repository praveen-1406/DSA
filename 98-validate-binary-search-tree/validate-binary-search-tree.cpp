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
    bool preorder(TreeNode* node,long long start,long long end){
        if(node==nullptr)   return true;
        if(node->val <= start || node->val >= end)  return false;
        // if(node->left && (node->left->val >= node->val))  return false;
        // if(node->right && (node->right->val <= node->val))  return false;
        return preorder(node->left,start,node->val) && preorder(node->right,node->val,end);
    }
    bool isValidBST(TreeNode* root) {
        return preorder(root,LLONG_MIN,LLONG_MAX);
    }
};
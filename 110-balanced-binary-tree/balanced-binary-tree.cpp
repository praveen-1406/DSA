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
    // bool ans=true;
    int check(TreeNode*node){
        if(node==nullptr)   return 0;
        int h1= check(node->left);
        int h2= check(node->right);
        if(h1==-1||h2==-1)  return -1;
        if(abs(h1-h2)>1)    return -1;   
        return 1+max(h1,h2);
    }

    bool isBalanced(TreeNode* root) {
        int height=check(root);
        if(height==-1)  return false;
        else    return true;
    }
};
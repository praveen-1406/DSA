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
    bool ans=true;
    int recursive(TreeNode*node){
        if(node==nullptr)   return 0;
        int h1= recursive(node->left);
        int h2= recursive(node->right);
        if(abs(h1-h2)>1)    ans=false;   
        return 1+max(h1,h2);
    }

    bool isBalanced(TreeNode* root) {
        recursive(root);
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool ancestor(TreeNode* node,TreeNode*p,TreeNode*q,TreeNode*&ans){
        if(node==nullptr)   return false;
        bool left=ancestor(node->left,p,q,ans);
        bool right=ancestor(node->right,p,q,ans);
        if(left && right){
            ans=node;
            return true;
        }else if(left || right){
            if(node==p||node==q)    ans=node;
            return true;
        }

        if(node==p || node==q){
            return true;
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ans=nullptr;
        ancestor(root,p,q,ans);
        return ans;
    }
};


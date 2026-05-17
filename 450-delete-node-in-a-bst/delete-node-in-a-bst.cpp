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
    TreeNode* findRightMost(TreeNode*node){
        if(node->right==nullptr)    return node;
        return findRightMost(node->right);
    }
    TreeNode*helper(TreeNode*node){
        if(node==nullptr)   return nullptr;
        if(node->left==nullptr)     return node->right;
        if(node->right==nullptr)    return node->left;
        TreeNode*rightMost=findRightMost(node->left);
        rightMost->right=node->right;
        TreeNode* newRoot=node->left;
        delete node;
        return newRoot;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)   return nullptr;
        if(root->val==key){
            return helper(root);
        }
        TreeNode*cur=root;
        while(cur){
            if(cur->left && cur->left->val==key){
                cur->left=helper(cur->left);
                return root;
            }else if(cur->right && cur->right->val==key){
                cur->right=helper(cur->right);
                return root;
            }
            if(cur->val > key)      cur=cur->left;
            else    cur=cur->right;
        }
        return root;
    }
};
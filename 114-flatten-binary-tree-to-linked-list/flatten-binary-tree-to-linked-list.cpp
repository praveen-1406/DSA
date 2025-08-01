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

    TreeNode* preorder(TreeNode* node){
        if(!node) return nullptr;
        TreeNode*left=node->left;
        TreeNode*right=node->right;
        TreeNode*terminal=node;
        if(left){
            TreeNode*lSubTree=preorder(left);
            node->left=nullptr;
            node->right=lSubTree;
            while(lSubTree->right!=nullptr){
                lSubTree=lSubTree->right;
            }
            terminal=lSubTree;
        }
        if(right){
            TreeNode*rSubTree=preorder(right);
            terminal->right=rSubTree;
        }
        return node;
    }

    void flatten(TreeNode* root) {
        preorder(root);
    }
};
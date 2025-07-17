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
    int traversal(TreeNode* node,int height){
        if(node==nullptr)   return height;
        int h1=traversal(node->left,height+1);
        int h2=traversal(node->right,height+1);
        return max(h1,h2);
    }

    int maxDepth(TreeNode* root) {
        return traversal(root,0);
    }
};
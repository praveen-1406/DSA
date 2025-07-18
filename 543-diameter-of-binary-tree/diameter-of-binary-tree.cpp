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
    // int maxiDia=0;
    int height(TreeNode*node,int &maxiDia){
        if(node==nullptr)   return 0;
        int hLeft=height(node->left,maxiDia);
        int hRight=height(node->right,maxiDia);
        maxiDia=max(maxiDia,hLeft+hRight);
        return 1+max(hLeft,hRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};
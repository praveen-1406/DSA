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
    int inorder(TreeNode* node,int sum){
        if(node==nullptr)   return 0;
        if(node->left==nullptr && node->right==nullptr){
            sum= (sum<<1)|(node->val);
            return sum;
        }
        sum=(sum<<1)|(node->val);
        int left=inorder(node->left,sum);
        int right=inorder(node->right,sum);
        return left+right;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return inorder(root,0);
        
    }
};
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

    int height(TreeNode*node,int &maxPSum){
        if(node==nullptr)   return 0;
        int lSum=height(node->left,maxPSum);
        int rSum=height(node->right,maxPSum);
        maxPSum=max(maxPSum,lSum+rSum+node->val);
        int ans=node->val+max(lSum,rSum);
        if(ans<0)   return 0;
        else    return ans;
    }

    int maxPathSum(TreeNode* root) {
        int pathSumMaximum=INT_MIN;
        height(root,pathSumMaximum);
        return pathSumMaximum;
    }
};
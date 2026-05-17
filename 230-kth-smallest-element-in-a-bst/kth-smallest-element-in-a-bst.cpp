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
    int helper(TreeNode*root,int k,vector<int>&sorted){
        if(root==nullptr)   return -1;
        int ans=-1;
        if(root->left)  ans=helper(root->left,k,sorted);
        if(ans!=-1)     return ans;

        sorted.push_back(root->val);

        if(root->right) ans=helper(root->right,k,sorted);
        if(ans!=-1)     return ans;

        if(sorted.size()>=k)    return sorted[k-1];

        return -1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>sorted;
        return helper(root,k,sorted);
    }
};
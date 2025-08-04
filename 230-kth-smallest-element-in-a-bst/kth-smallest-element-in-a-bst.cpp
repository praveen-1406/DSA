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
    void preorder(TreeNode*root,set<int>&st){
        if(root==nullptr)   return;
        st.insert(root->val);
        preorder(root->left,st);
        preorder(root->right,st);
    }
    int kthSmallest(TreeNode* root, int k) {
        set<int>st;
        preorder(root,st);

        for(auto it:st){
            if(k==1)    return it;
            k--;
        }
        return -1;
    }
};
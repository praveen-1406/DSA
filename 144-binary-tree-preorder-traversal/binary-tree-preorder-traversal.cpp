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

    // void Preorder(TreeNode*node,vector<int>&ans){
    //     if(node==nullptr)   return;
    //     ans.push_back(node->val);
    //     Preorder(node->left,ans);
    //     Preorder(node->right,ans);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // Preorder(root,ans);
        // return ans;

        // Iterative
        stack<TreeNode*>st;
        vector<int>ans;
        if(root==nullptr)   return ans;
        st.push(root);
        while(!st.empty()){           
            TreeNode*node=st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=nullptr)    st.push(node->right);
            if(node->left!=nullptr)    st.push(node->left);
        }
        return ans;
    }
};
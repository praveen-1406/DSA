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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        vector<int>ans;
        if(root==nullptr)   return ans;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int row=q.front().second;
            q.pop();
            mp[row]=node->val;
            if(node->left)      q.push({node->left,row+1});
            if(node->right)     q.push({node->right,row+1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
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

    // void BFS(vector<vector<int>>&ans,queue<TreeNode*>q){
    //     if(q.empty())   return ;
    //     queue<TreeNode*>next;
    //     vector<int>level;
    //     while(!q.empty()){
    //         level.push_back(q.front()->val);
    //         if(q.front()->left!=nullptr) next.push(q.front()->left);
    //         if(q.front()->right!=nullptr) next.push(q.front()->right);
    //         q.pop();
    //     }
    //     ans.push_back(level);
    //     BFS(ans,next);
    // }

    vector<vector<int>> levelOrder(TreeNode* root) {
        // if(root==nullptr)   return {};
        // vector<vector<int>>ans;
        // queue<TreeNode*>q;
        // q.push(root);
        // BFS(ans,q);
        // return ans;
        vector<vector<int>>ans;
        if(root==nullptr)   return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr)     q.push(node->left);
                if(node->right!=nullptr)    q.push(node->right);
                level.push_back(node->val);  
            }
            ans.push_back(level);
        }
        return ans;
    }
};
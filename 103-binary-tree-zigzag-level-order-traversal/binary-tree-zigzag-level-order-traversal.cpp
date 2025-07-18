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

    void levelOrder(TreeNode*node,vector<vector<int>>&ans){
        
        queue<TreeNode*>q;
        q.push(node);
        bool lr=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                int index=(lr)?i:size-1-i;
                level[index]=temp->val;
                
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            ans.push_back(level);  
            lr=!lr;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)   return ans;
        levelOrder(root,ans);
        return ans;
    }
};
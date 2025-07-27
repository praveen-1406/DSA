/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //node==traget node: distance=0(initially)
    void markParent(TreeNode*node,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                parent[cur->left]=cur;
            }
            if(cur->right){
                q.push(cur->right);
                parent[cur->right]=cur;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markParent(root,parent);

        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            if(dist++==k)   break;
            for(int i=0;i<size;i++){
                TreeNode*cur=q.front();
                q.pop();
                if(cur->left && !visited[cur->left]){
                    visited[cur->left]=true;
                    q.push(cur->left);
                }
                if(cur->right && !visited[cur->right]){
                    visited[cur->right]=true;
                    q.push(cur->right);
                }
                if(cur!=root && !visited[parent[cur]]){
                    visited[parent[cur]]=true;
                    q.push(parent[cur]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};
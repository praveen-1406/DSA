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
    void parentMarking(TreeNode*node,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            if(cur->left){
                parent[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
    
    TreeNode* preorder(TreeNode* node, int start){
        if(node==nullptr)  return nullptr;
        if(node->val==start)   return node;
        TreeNode*left = preorder(node->left,start);
        if(left)    return left;
        return preorder(node->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL)   return 0;
        unordered_map<TreeNode*,TreeNode*>parent;
        parentMarking(root,parent);

        unordered_map<TreeNode*,bool>burned;
        queue<TreeNode*>q;

        TreeNode*node=preorder(root,start);

        q.push(node);
        burned[node]=true;
        int time=0;
        while(!q.empty()){
            int size=q.size();
        
            for(int i=0;i<size;i++){
                TreeNode*cur=q.front();
                q.pop();
                if(cur->left && !burned[cur->left]){
                    q.push(cur->left);
                    burned[cur->left]=true;
                }
                if(cur->right && !burned[cur->right]){
                    q.push(cur->right);
                    burned[cur->right]=true;
                }
                if(cur!=root && !burned[parent[cur]]){
                    q.push(parent[cur]);
                    burned[parent[cur]]=true;
                }   
            }
            if(!q.empty())  time++;
        }
        return time;
    }
};
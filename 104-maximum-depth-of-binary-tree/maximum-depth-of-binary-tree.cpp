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
    // int traversal(TreeNode* node,int height){
    //     if(node==nullptr)   return height;
    //     int h1=traversal(node->left,height+1);
    //     int h2=traversal(node->right,height+1);
    //     return max(h1,h2);
    // }
    // int recursive(TreeNode* node){
    //     if(node==nullptr)   return 0;
    //     int h1=recursive(node->left);
    //     int h2=recursive(node->right);
    //     return 1+max(h1,h2);
    // }
    int levelOrder(TreeNode* root){
        if(root==nullptr)   return 0;
        queue<TreeNode*>q;
        int height=0;
        q.push(root);
        while(!q.empty()){
            height++;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left!=nullptr)     q.push(node->left);
                if(node->right!=nullptr)    q.push(node->right);
            }
        }
        return height;
    }

    int maxDepth(TreeNode* root) {
        // return traversal(root,0);
        // return recursive(root);
        return levelOrder(root);
    }
};
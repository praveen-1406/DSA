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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode*ans=new TreeNode(val);
            return ans;
        }
        TreeNode*node=root;
        while(node){
            if(val<node->val){
                if(node->left==nullptr){
                    node->left=new TreeNode(val);
                    return root;
                }
                else{
                    node=node->left;
                }  
            }
            else{
                if(node->right==nullptr){
                    node->right=new TreeNode(val);
                    return root;
                }
                else{
                    node=node->right;
                }
            }
        }
        return root;
    }
};
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
    // void preorder(TreeNode*root,set<int>&st){
    //     if(root==nullptr)   return;
    //     st.insert(root->val);
    //     preorder(root->left,st);
    //     preorder(root->right,st);
    // }
    int kthSmallest(TreeNode* root, int k) {
        // set<int>st;
        // preorder(root,st);

        // for(auto it:st){
        //     if(k==1)    return it;
        //     k--;
        // }
        // return -1;

        //Morris inorder traversal.
        TreeNode*node=root;
        int cnt=0,result=-1;
        while(node){
            if(node->left==nullptr){
                cnt++;
                if(cnt==k)  result= node->val;
                node=node->right;
            }else{
                TreeNode*rightMost=node->left;
                while(rightMost->right && rightMost->right!=node)  rightMost=rightMost->right;
                if(rightMost->right==node){
                    cnt++;
                    if(cnt==k)  result= node->val;
                    rightMost->right=nullptr;
                    node=node->right;
                }else{
                    rightMost->right=node;
                    node=node->left;
                }
            }
        }
        return result;
    }
};
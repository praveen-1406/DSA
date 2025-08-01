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

    //  Recursive:
    // void Inorder(TreeNode* node,vector<int>&ans){
    //     if(node==nullptr)   return ;
    //     Inorder(node->left,ans);
    //     ans.push_back(node->val);
    //     Inorder(node->right,ans);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // Inorder(root,ans);
        // return ans;

        // Iterative:
        // vector<int>ans;
        // if(root==nullptr)   return ans;
        // stack<TreeNode*>st;
        // TreeNode*node=root;
        // while(true){
        //     if(node!=nullptr)   {
        //         st.push(node);
        //         node=node->left;
        //     }else{
        //         if(st.empty())  break;
        //         node=st.top();
        //         st.pop();
        //         ans.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return ans;


        //  Morris Traversal:
        vector<int>inorder;
        TreeNode* cur=root;
        while(cur){
            if(cur->left==nullptr){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=nullptr;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};
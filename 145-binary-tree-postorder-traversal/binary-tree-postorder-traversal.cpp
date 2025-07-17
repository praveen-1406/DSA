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

    // void Postorder(TreeNode*node,vector<int>&ans){
    //     if(node==nullptr)   return;
    //     Postorder(node->left,ans);
    //     Postorder(node->right,ans);
    //     ans.push_back(node->val);
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // Postorder(root,ans);
        // return ans;

        // Iterative-using 2 stacks
        // vector<int>ans;
        // if(root==nullptr)   return ans;
        // stack<TreeNode*>st1,st2;
        // st1.push(root);
        // while(!st1.empty()){
        //     root=st1.top();
        //     st1.pop();
        //     st2.push(root);
        //     if(root->left)  st1.push(root->left);
        //     if(root->right) st1.push(root->right);
        // }
        // while(!st2.empty()){
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return ans;

        // Iterative-using 1 stack
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* cur=root;
        while(cur!=nullptr || !st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur=cur->left;
            }else{
                TreeNode*temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else   cur=temp;
                
            }
        }
        return ans;
    }
};


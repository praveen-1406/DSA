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

class BSTIterator{
    stack<TreeNode*>st;
    bool reverse=true;
public: 
    BSTIterator(TreeNode*root,bool isReverse){
        this->reverse=isReverse;
        pushAll(root);
    }
    
    void pushAll(TreeNode*node){
        for(;node!=nullptr;){
            st.push(node);
            if(reverse==true)   node=node->right;
            else    node=node->left;
        }
    }
    int next(){
        TreeNode*node=st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        long long  i=l.next();
        long long  j=r.next();
        while(i<j){
            if(i+j==k)  return true;
            else if(i+j < k)    i=l.next();
            else    j=r.next();
        }
        return false;
    }
};
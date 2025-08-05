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
    // void createBST(TreeNode*node,vector<int>&preorder,int &idx,int end){
    //     if(idx==preorder.size())    return ;
    //     TreeNode*cur=new TreeNode(preorder[idx]);
    //     if(cur->val < node->val) {
    //         node->left=cur;
    //         createBST(cur,preorder,++idx,node->val);
    //     }
    //     if(idx<preorder.size())    cur=new TreeNode(preorder[idx]);
    //     if(cur->val > node->val && cur->val < end){
    //         node->right=cur;
    //         createBST(cur,preorder,++idx,end);
    //     }
    //     // else idx--;
    // }
    TreeNode*build(vector<int>& preorder,int &i,int bound){
        if(i==preorder.size()||preorder[i]>bound)   return nullptr;
        TreeNode*root=new TreeNode(preorder[i++]);
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // TreeNode*root=new TreeNode(preorder[0]);
        // int idx=1;
        // createBST(root,preorder,idx,1001);
        // return root;
        int i=0;
        return build(preorder,i,INT_MAX);
    }
};
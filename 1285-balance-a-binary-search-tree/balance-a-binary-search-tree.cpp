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
    void inorder(TreeNode* node,vector<int>&nodes){
        if(!node)   return;
        if(node->left)  inorder(node->left,nodes);
        nodes.push_back(node->val);
        if(node->right) inorder(node->right,nodes);

    }
    TreeNode* balBST(int l,int r,vector<int>&nodes){
        if(r<l) return nullptr;
        int mid=l+(r-l+1)/2;
        TreeNode*node=new TreeNode(nodes[mid]);
        node->left=balBST(l,mid-1,nodes);
        node->right=balBST(mid+1,r,nodes);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>nodes;
        inorder(root,nodes);
        int n=nodes.size();
        int rval=nodes[n/2];
        return balBST(0,n-1,nodes);
    }
};
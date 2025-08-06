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
    void inorder(TreeNode*node,vector<TreeNode*>&in){
        if(node==nullptr)   return ;
        inorder(node->left,in);
        in.push_back(node);
        inorder(node->right,in);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>in;
        inorder(root,in);
        int i=1,j=in.size()-2;
        TreeNode*node1=nullptr,*node2=nullptr;
        while(true){
            if(!node1 && in[i-1]->val > in[i]->val)   node1=in[i-1];
            if(!node2 && in[j+1]->val < in[j]->val)   node2=in[j+1];
            if(node1 && node2)  break;
            i++;
            j--;
        }
        if(node1 && node2){
            int tmp=node1->val;
            node1->val=node2->val;
            node2->val=tmp;
        }
        
    }
};
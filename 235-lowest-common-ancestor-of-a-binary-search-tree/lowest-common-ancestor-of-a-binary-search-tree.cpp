/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode*pnode=root,*qnode=root,*ans=root;
        // while(pnode!=p || qnode!=q){
        //     if(pnode==qnode)    ans=pnode;

        //     if(pnode->val > p->val) pnode=pnode->left;
        //     else if(pnode->val < p->val)   pnode=pnode->right;

        //     if(qnode->val > q->val) qnode=qnode->left;
        //     else if(qnode->val < q->val)   qnode=qnode->right;
        // }
        // return ans;
        TreeNode*node=root;
        while(true){
            if(node->val > p->val && node->val > q->val)    node=node->left;
            else if(node->val < p->val && node->val < q->val)   node=node->right;
            else    return node;
        }
    }
};
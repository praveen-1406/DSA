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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur=root;
        int cnt=0,result=-1;
        while(cur){
            if(cur->left==nullptr){
                cnt++;
                if(cnt==k)  result= cur->val;
                cur=cur->right;
            }else{
                TreeNode*rightMost=cur->left;
                while(rightMost->right!=nullptr && rightMost->right!=cur)    rightMost=rightMost->right;
                if(rightMost->right==cur){
                    cnt++;
                    if(cnt==k)  result= cur->val;
                    rightMost->right=nullptr;
                    cur=cur->right;
                }
                else{
                    rightMost->right=cur;
                    cur=cur->left;
                }
            }
        }
            return result;
    }
};
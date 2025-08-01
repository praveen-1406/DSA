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

    // TreeNode* preorder(TreeNode* node){
    //     if(!node) return nullptr;
    //     TreeNode*left=node->left;
    //     TreeNode*right=node->right;
    //     TreeNode*terminal=node;
    //     if(left){
    //         TreeNode*lSubTree=preorder(left);
    //         node->left=nullptr;
    //         node->right=lSubTree;
    //         while(lSubTree->right!=nullptr){
    //             lSubTree=lSubTree->right;
    //         }
    //         terminal=lSubTree;
    //     }
    //     if(right){
    //         TreeNode*rSubTree=preorder(right);
    //         terminal->right=rSubTree;
    //     }
    //     return node;
    // }

    TreeNode* prev=nullptr;

    void flatten(TreeNode* node) {
        // preorder(root);
        // if(node==nullptr)   return;
        // flatten(node->right);
        // flatten(node->left);
        // node->right=prev;
        // node->left=nullptr;
        // prev=node;
        // if(node==nullptr)   return;
        // stack<TreeNode*>st;
        // st.push(node);
        // while(!st.empty()){
        //     TreeNode*cur=st.top();
        //     st.pop();
        //     if(cur->right)  st.push(cur->right);
        //     if(cur->left)  st.push(cur->left);
        //     if(!st.empty())  cur->right=st.top();
        //     cur->left=nullptr;
        // }

        // Morris Traversal-Threaded Binary Tree
        TreeNode* cur=node;
        while(cur){
            if(cur->left){
                TreeNode*prev=cur->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=nullptr;
            }
            cur=cur->right;
        }
    }
};
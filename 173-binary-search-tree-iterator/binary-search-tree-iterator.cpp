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
class BSTIterator {
public:
    // vector<int>inorder;
    // TreeNode*root=nullptr;
    // int idx=-1;
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        // this->root=root;
        // MorrisInorder(root);
        // idx++;
        TreeNode*node=root;
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    
    // void MorrisInorder(TreeNode*root){
    //     TreeNode*node=root;
    //     while(node){
    //         if(node->left==nullptr){
    //             inorder.push_back(node->val);
    //             node=node->right;
    //         }
    //         else{
    //             TreeNode*pre=node->left;
    //             while(pre->right && pre->right!=node)   pre=pre->right;
    //             if(pre->right==node){
    //                 inorder.push_back(node->val);
    //                 pre->right=nullptr;
    //                 node=node->right;
    //             }else{
    //                 pre->right=node;
    //                 node=node->left;
    //             }  
    //         }
    //     }
    // }

    int next() {
        // return inorder[idx++];
        int ans=st.top()->val;
        TreeNode*node=st.top()->right;
        st.pop();
        while(node){
            st.push(node);
            node=node->left;
        }
        return ans;
    }
    
    bool hasNext() {
        // if(idx<inorder.size())  return true;
        // else    return false;
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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
    bool isLeaf(TreeNode*node){
        return (!node->left) && (!node->right);
    }
    void getPath(TreeNode*node,vector<string>&ans,string&a){
        if(node==nullptr)   return;
        if(a.size())       a=a+"->"+to_string(node->val);
        else        a=to_string(node->val);
        if(isLeaf(node)){
            ans.push_back(a);
        }
        if(node->left)  getPath(node->left,ans,a);
        if(node->right) getPath(node->right,ans,a);
        size_t pos=a.rfind("->");
        a=a.substr(0,pos);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string a="";
        getPath(root,ans,a);
        return ans;
    }
};
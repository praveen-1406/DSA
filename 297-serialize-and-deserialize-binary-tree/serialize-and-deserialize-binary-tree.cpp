/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";
        queue<TreeNode*>q;
        q.push(root);
        string ser="";
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr)   ser.append("#,");
            else    ser.append(to_string(node->val)+",");
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)  return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")    node->left=nullptr;
            else   {
                TreeNode* left=new TreeNode(stoi(str));
                node->left=left;
                q.push(left);
            }
            getline(s,str,',');
            if(str=="#")    node->right=nullptr;
            else{
                TreeNode* right=new TreeNode(stoi(str));
                node->right=right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
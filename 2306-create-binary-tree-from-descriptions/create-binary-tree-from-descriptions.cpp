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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        TreeNode*root;
        unordered_map<TreeNode*,TreeNode*>parentMap;
        for(auto i:descriptions){
            int parent=i[0];
            int child=i[1];
            int isLeft=i[2];
            TreeNode* p,*c;
            if(nodes.find(parent)!=nodes.end()){
                p=nodes[parent];
            }else{ 
                p=new TreeNode(parent);
                nodes[parent]=p;
                root=p;
            }
            if(nodes.find(child)!=nodes.end()){
                c=nodes[child];
            }else{
                c=new TreeNode(child);
                nodes[child]=c;
            }
            if(isLeft)  p->left=c;
            else    p->right=c;

            parentMap[c]=p;
        }

        while(parentMap.find(root)!=parentMap.end()){
            root=parentMap[root];
        }
        return root;
    }
};
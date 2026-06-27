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
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        int o=dia(root,res);
        return res;
        
    }

    int dia(TreeNode* root,int & res){

        if(root==nullptr){
            return 0;
        }
        int l=dia(root->left,res);
        int r=dia(root->right,res);

        if(res<(l+r)){
            res=l+r;
        }
        return max(l,r)+1;
    }
};
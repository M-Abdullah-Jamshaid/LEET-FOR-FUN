/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) { return height(root) != -1; }

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);
        if(l==-1||r==-1){
            return -1;
        }

        int res = l - r;
        if (res < 0) {
            res = (-1) * res;
        }

        if (res <= 1) {
            return max(l,r) + 1;
        } else {
            return -1;
        }
    }
};
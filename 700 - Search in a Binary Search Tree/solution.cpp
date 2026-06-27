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
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* roo = aaa(root, val);
        if (roo!=nullptr&&roo->val == val) {
            return roo;
        } else {
            return nullptr;
        }
    }
    TreeNode* aaa(TreeNode* root, int val){
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* r1 = searchBST(root->left, val);

        if (r1 != nullptr && r1->val == val) {
            return r1;
        }

        TreeNode* r2 = searchBST(root->right, val);
        if (r2 != nullptr && r2->val == val) {
            return r2;
        }


        return root;
    }
};
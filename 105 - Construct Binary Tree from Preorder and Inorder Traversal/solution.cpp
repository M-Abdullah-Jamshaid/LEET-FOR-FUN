
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int preIndex = 0; 
        
        return build(preorder, 0, inorder.size() - 1, inMap, preIndex);
    }

private:
    TreeNode* build(std::vector<int>& preorder, int inStart, int inEnd, 
                    std::unordered_map<int, int>& inMap, int& preIndex) {
        
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preIndex];
        preIndex++; // Move the pointer to the next root
        
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];

        root->left = build(preorder, inStart, inIndex - 1, inMap, preIndex);

        root->right = build(preorder, inIndex + 1, inEnd, inMap, preIndex);

        return root;
    }
};
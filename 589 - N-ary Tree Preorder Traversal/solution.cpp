class Solution {
public:
    // To store the output result...
    vector<int> output;
    void traverse(Node* root) {
        // Base case: if the tree is empty...
        if(root == NULL) return;
        // Push the value of the root node to the output...
        output.push_back(root->val);
        // Recursively traverse each node in the children array...
        for(auto node:root->children)
            traverse(node);
    }
    vector<int> preorder(Node* root) {
        output.clear();
        traverse(root);
        return output;
    }
};
class CBTInserter {
public:
    TreeNode* root;
    int cnt = 0;
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        cnt = getCount(root);
    }
    
    int insert(int v) {
        cnt++;
		//Getting the position of first set bit
        int msb_i = log2(cnt);
		//Removing the first set bit
        int dir = (cnt & ~(1 << msb_i));
        
        
        TreeNode* temp = root;
        
        int i = msb_i - 1;
		//i = 0 will be the position of node you want to insert
        while(i >= 1) {
            if(dir & (1 << i)) 
                temp = temp->right;
            else
                temp = temp->left;
            
            i--;
        }
        if(!temp->left)
            temp->left = new TreeNode(v);
        else
            temp->right = new TreeNode(v);
        
        return temp->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
    
    int getCount(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        return 1 + getCount(root->left) + getCount(root->right);
    }
};
class Solution {
public:
    int minDiff = INT_MAX;
    
    void helper(TreeNode* root, TreeNode* node) {
        if(node == nullptr) return;
        
        if(root != node) { // Don't compare node with itself
            minDiff = min(minDiff, abs(root->val - node->val));
        }
        
        helper(root, node->left);
        helper(root, node->right);
    }
    
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        
        // Compare current node with all nodes in its subtree
        helper(root, root->left);
        helper(root, root->right);
        
        // Recursively do this for all nodes
        dfs(root->left);
        dfs(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minDiff;
    }
};
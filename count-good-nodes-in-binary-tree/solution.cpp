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
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
    int dfs(TreeNode* node,int maxval){
        if(node==nullptr) return 0;
        int count = 0;
        if(node->val>=maxval){
            count = 1;
            maxval = node->val;
        }
        count += dfs(node->left,maxval);
        count += dfs(node->right,maxval);
        return count;
    }
};
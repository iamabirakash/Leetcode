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
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        int take = root->val;
        if(root->left!=nullptr){
            take += rob(root->left->left);
            take += rob(root->left->right);
        }
        if(root->right!=nullptr){
            take += rob(root->right->left);
            take += rob(root->right->right);
        }
        int skip = rob(root->left) +rob(root->right);

        mp[root] = max(skip,take);
        return mp[root];
    }
};
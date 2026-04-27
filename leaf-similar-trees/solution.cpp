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
    void getLeaves(TreeNode* root, vector<int>& leaves){
        if(!root) return;
        if(!root->left && !root->right){
            leaves.push_back(root->val);
            return;
        }
        getLeaves(root->left,leaves);
        getLeaves(root->right,leaves);
    } 
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        getLeaves(root1,res1);
        getLeaves(root2,res2);
        return res1==res2;
    }
};
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
    void helper(TreeNode* root, int targetSum,vector<vector<int>>& res,vector<int>& ans){
        if(root==nullptr) return;
        ans.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && targetSum-root->val==0){
            res.push_back(ans);
        }
        helper(root->left,targetSum-root->val,res,ans);
        helper(root->right,targetSum-root->val,res,ans);
        ans.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(root,targetSum,res,ans);
        return res;
    }
};
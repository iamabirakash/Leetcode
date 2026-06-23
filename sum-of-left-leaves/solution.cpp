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
    int ans = 0;
    void helper(TreeNode* root,bool isLeft){
        if(root==nullptr) return;
        if(isLeft && (root->left==nullptr && root->right==nullptr)){
            ans+=root->val;
            // return;
        }
        helper(root->left,true);
        helper(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        helper(root->left,true);
        helper(root->right,false);
        return ans;
    }
};
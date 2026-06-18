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
    void helper(vector<string>& res,TreeNode* root,string str){
        if(root == nullptr) return;
        if(str.empty()) {
            str = to_string(root->val);
        } else {
            str += "->" + to_string(root->val);
        }
        if(root->left== nullptr and root->right==nullptr){
            res.push_back(str);
            return;
        }
        helper(res,root->right,str);
        helper(res,root->left,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==nullptr) return res;
        string str = "";
        helper(res,root,str);
        return res;
    }
};
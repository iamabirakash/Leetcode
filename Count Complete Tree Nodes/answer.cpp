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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
        // int l = count(root->left);
        // int r = count(root->right);
        // return 1+countNodes(root->left)+countNodes(root->right);
    }
    // int count(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     return 1+count(root->left)+count(root->right);
    // }
};

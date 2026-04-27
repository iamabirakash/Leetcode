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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0,level=0;
        int maxsum = INT_MIN;
        while(!q.empty()){
            level++;
            int cursum = 0;
            for(int i=q.size();i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                cursum += node->val;
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
            if(maxsum < cursum){
                maxsum = cursum;
                ans = level;
            }
        }
        return ans;
    }
};
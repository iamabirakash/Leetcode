/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int countPairs(TreeNode root, int distance) {
        int[] result = new int[1];
        dfs(root, distance, result);
        return result[0];
    }
    
    private int[] dfs(TreeNode node, int distance, int[] result) {
        if (node == null) {
            return new int[distance + 1];
        }
        
        if (node.left == null && node.right == null) {
            int[] leafDistances = new int[distance + 1];
            leafDistances[1] = 1;
            return leafDistances;
        }
        
        int[] leftDistances = dfs(node.left, distance, result);
        int[] rightDistances = dfs(node.right, distance, result);
        
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance) {
                    result[0] += leftDistances[i] * rightDistances[j];
                }
            }
        }
        
        int[] currentDistances = new int[distance + 1];
        for (int i = 1; i < distance; i++) {
            currentDistances[i + 1] = leftDistances[i] + rightDistances[i];
        }
        
        return currentDistances;
    }
}
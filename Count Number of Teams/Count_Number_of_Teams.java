class Solution {
    boolean flag = true;

    public int numTeams(int[] rating) {
        int count = 0;

        int[][][] dp = new int[rating.length][rating.length+1][4];
        for(int[][] arr : dp) {
            for(int[] ar : arr) Arrays.fill(ar, -1);
        }

        count += helper(rating, 0, -1, 0, dp);
        
        flag = false;
        for(int[][] arr : dp) {
            for(int[] ar : arr) Arrays.fill(ar, -1);
        }
        
        count += helper(rating, 0, -1, 0, dp);

        return count;
    }

    private int helper(int[] rating, int index, int prevIndex, int len, int[][][] dp) {
        if(len == 3) return 1;
        if(index == rating.length) return 0;

        if(dp[index][prevIndex+1][len] != -1) return dp[index][prevIndex+1][len];

        int count = 0;
        if(prevIndex == -1 || (flag ? rating[index] > rating[prevIndex] : rating[index] < rating[prevIndex])) count += helper(rating, index+1, index, len+1, dp);
        count += helper(rating, index+1, prevIndex, len, dp);

        return dp[index][prevIndex+1][len] = count;
    }
}

// class Solution {
//     public int numTeams(int[] rating) {
//         int n = rating.length;
//         if (n < 3) return 0;

//         int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
//         for (int num : rating) {
//             min = Math.min(min, num);
//             max = Math.max(max, num);
//         }
        
//         int[] leftTree = new int[max - min + 2];
//         int[] rightTree = new int[max - min + 2];
        
//         for (int num : rating) {
//             update(rightTree, num - min, 1);
//         }
        
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             update(rightTree, rating[i] - min, -1);
            
//             int lessLeft = query(leftTree, rating[i] - min - 1);
//             int greaterLeft = i - lessLeft;
            
//             int lessRight = query(rightTree, rating[i] - min - 1);
//             int greaterRight = (n - i - 1) - lessRight;
            
//             count += lessLeft * greaterRight + greaterLeft * lessRight;
            
//             update(leftTree, rating[i] - min, 1);
//         }
        
//         return count;
//     }

//     private void update(int[] tree, int index, int value) {
//         index++;
//         while (index < tree.length) {
//             tree[index] += value;
//             index += index & (-index);
//         }
//     }

//     private int query(int[] tree, int index) {
//         int sum = 0;
//         index++;
//         while (index > 0) {
//             sum += tree[index];
//             index -= index & (-index);
//         }
//         return sum;
//     }
// }
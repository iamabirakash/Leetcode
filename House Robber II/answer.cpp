class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        vector<int> dp1(n,0);
        dp1[1] = nums[1];
        dp1[2] = max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            dp1[i] = max(dp1[i-1],nums[i]+dp1[i-2]);
        }
        return max(dp[n-2],dp1[n-1]);
    }
    // int robHelper(vector<int>& nums, int start, int end) {
    //     if (start == end) return nums[start];
    //     int prev1 = 0, prev2 = 0;
    //     for (int i = start; i <= end; i++) {
    //         int take = nums[i] + prev2;
    //         int notTake = prev1;
    //         int curr = max(take, notTake);
    //         prev2 = prev1;
    //         prev1 = curr;
    //     }
    //     return prev1;
    // }

    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 1) return nums[0];

    //     if (n % 2 == 0) {
    //         return robHelper(nums, 0, n - 1);
    //     } else {
    //         int robFirstToSecondLast = robHelper(nums, 0, n - 2);
    //         int robSecondToLast = robHelper(nums, 1, n - 1);
    //         return max(robFirstToSecondLast, robSecondToLast);
    //     }
    // }
};

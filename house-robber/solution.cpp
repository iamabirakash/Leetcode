class Solution {
public:
    // int solve(vector<int>& nums,int i,vector<int>& dp){
    //     if(i>=nums.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int take = nums[i] + solve(nums,i+2,dp);
    //     int skip = solve(nums,i+1,dp);
    //     return dp[i] = max(take,skip);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n+1,-1);
    //     return solve(nums,0,dp);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};
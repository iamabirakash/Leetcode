class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n]!=0) return dp[n];
        dp[n] = solve(n-1,dp) + solve(n-2,dp) + solve(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,0);
        return solve(n,dp);
    }
};

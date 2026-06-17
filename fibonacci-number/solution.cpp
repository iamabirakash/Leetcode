class Solution {
public:
    // int solve(int n, vector<int>& dp) {
    //     if (n <= 1) return n;
    //     if (dp[n] != 0) return dp[n];
    //     dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    //     return dp[n];
    // }
    // int fib(int n) {
    //     vector<int> dp(n + 1,0);
    //     return solve(n, dp);
    // }
    int fib(int n) {
        // if (n <= 1) return n;
        // vector<int> dp(n + 1,0);
        // dp[0] = 0; dp[1] = 1;
        // for(int i=2;i<=n;i++) dp[i] = dp[i-1]+dp[i-2];
        // return dp[n];
        if(n==0 || n==1) return n;
        return fib(n-1)+fib(n-2);
    }
};
class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return pair(n,dp);
    }
    int pair(int n,vector<int>& dp){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = pair(n-1,dp)+(n-1)*pair(n-2,dp);
    }
};

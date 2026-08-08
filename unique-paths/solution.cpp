class Solution {
public:
    int find(int m,int n,vector<vector<int>>& dp,int i,int j){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = find(m,n,dp,i+1,j);
        int right = find(m,n,dp,i,j+1);
        return dp[i][j] = down+right;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return find(m,n,dp,0,0);
    }
};
class Solution {
public:
    int path(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right = path(i,j+1,m,n,grid,dp);
        int down = path(i+1,j,m,n,grid,dp);
        // int minm = min(path(i,j+1,m,n,grid,dp),path(i+1,j,m,n,grid,dp));
        int ans = grid[i][j] + min(right, down);
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return path(0,0,m,n,grid,dp);
    }
};

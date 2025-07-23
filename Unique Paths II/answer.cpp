class Solution {
public:
    int path(int i,int j,int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        if(i>=m || j>=n || obstacleGrid[i][j]) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = path(i,j+1,m,n,dp,obstacleGrid);
        int down = path(i+1,j,m,n,dp,obstacleGrid);
        return dp[i][j] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return path(0,0,m,n,dp,obstacleGrid);
    }
};

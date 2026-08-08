class Solution {
public:
    int find(int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid,int i,int j){
        if(i>=m || j>=n) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = find(m,n,dp,obstacleGrid,i+1,j);
        int right = find(m,n,dp,obstacleGrid,i,j+1);
        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return find(m,n,dp,obstacleGrid,0,0);
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<n;j++) {
                int mn = dp[i+1][j];
                if(j>0)
                    mn = min(mn,dp[i+1][j-1]);
                if(j<n-1)
                    mn = min(mn,dp[i+1][j+1]);
                dp[i][j] += mn;
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};


// class Solution {
// public:
//     int path(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
//         if(j<0 || j>=n) return INT_MAX;
//         if(i==n-1) return matrix[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int left = path(i+1,j-1,n,matrix,dp);
//         int down = path(i+1,j,n,matrix,dp);
//         int right = path(i+1,j+1,n,matrix,dp);
//         return dp[i][j] = matrix[i][j] + min({left,down,right});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         int ans = INT_MAX;
//         for(int j=0;j<n;j++) {
//             ans = min(ans,path(0,j,n,matrix,dp));
//         }
//         return ans;
//     }
// };

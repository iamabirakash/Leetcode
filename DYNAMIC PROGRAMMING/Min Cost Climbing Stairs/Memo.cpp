class Solution {
public:
    int minCost(vector<int>& cost,int idx,vector<int>& dp) {
        if(idx==0 || idx==1) return cost[idx];
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = cost[idx] + min(minCost(cost,idx-1,dp),minCost(cost,idx-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
    }
};

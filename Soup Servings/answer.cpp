vector<vector<double>> dp(4801, vector<double>(4801, 2.0f));
class Solution {
    public:
        double solve(int A, int B){
            if(B <= 0 && A > 0)
                return 0.0f;
            if(A <= 0 && B > 0)
                return 1.0f;
            if(A <= 0 && B <= 0)
                return 0.5f;
            if(dp[A][B] <= 1.0f)
                return dp[A][B];
            dp[A][B] = 0.25f * (solve(A - 100, B) + solve(A - 75, B - 25) + solve(A - 50, B - 50) + solve(A - 25,B - 75));
            return dp[A][B]; 
            
        }
        double soupServings(int n) {
            if(n > 4800)
                return 1;
            return solve(n, n);
        }
};

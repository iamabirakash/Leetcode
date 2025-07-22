class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int result = 0;
        vector<int> dp(text1.size());
        for(auto it: text2){
            int len = 0;
            for(int i=0;i<text1.size();i++){
                if(len<dp[i]){
                    len = dp[i];
                }else if(it==text1[i]){
                    dp[i] = len+1;
                    result = max(result,dp[i]);
                }
            }
        }
        return result;
    }
};

// #include <string>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
//         // Fill dp array where dp[i][j] = length of LCS of text1[0..i-1] and text2[0..j-1]
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (text1[i - 1] == text2[j - 1]) {
//                     dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match
//                 } else {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // No match, take max from previous substrings
//                 }
//             }
//         }
        
//         return dp[m][n];
//     }
// };

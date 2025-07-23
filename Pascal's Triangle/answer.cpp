class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < n; i++) {
            vector<int> row(i + 1, 0);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1;
                } else {
                    row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> pascal;
//         for(int i = 0; i < numRows; i++) {
//             vector<int> add(i + 1, 1); // all 1s
//             for(int j = 1; j < i; j++) {
//                 add[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
//             }
//             pascal.push_back(add);
//         }
//         return pascal;
//     }
// };

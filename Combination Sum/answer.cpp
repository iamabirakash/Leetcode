class Solution {
public:
    void helper(vector<int>& a, int start, vector<int>& current, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        for (int i = start; i < a.size(); i++) {
            if (a[i] <= target) {
                current.push_back(a[i]);                    // Choose the number
                helper(a, i, current, ans, target - a[i]);  // Recurse with reduced target
                current.pop_back();                         // Backtrack
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        helper(candidates, 0, current, result, target);
        return result;
    }
};

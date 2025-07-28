class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, count = 0;

        // Calculate the max OR value from all elements
        for (int num : nums) {
            maxOR |= num;
        }

        // Start DFS/backtracking
        dfs(nums, 0, 0, maxOR, count);
        return count;
    }

private:
    void dfs(const vector<int>& nums, int index, int currentOR, int maxOR, int& count) {
        if (index == nums.size()) {
            if (currentOR == maxOR) ++count;
            return;
        }

        // Include current element
        dfs(nums, index + 1, currentOR | nums[index], maxOR, count);
        // Exclude current element
        dfs(nums, index + 1, currentOR, maxOR, count);
    }
};

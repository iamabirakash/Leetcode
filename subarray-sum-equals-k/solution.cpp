class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, prefix_sum = 0;
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        
        for (int num : nums) {
            prefix_sum += num;
            if (prefix_counts.count(prefix_sum - k)) {
                count += prefix_counts[prefix_sum - k];
            }
            prefix_counts[prefix_sum]++;
        }
        
        return count;
    }
};

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<int> missing;
        
        for (int i = 1; i < nums.size(); i++) {
            // If there's a gap between consecutive elements
            for (int num = nums[i-1] + 1; num < nums[i]; num++) {
                missing.push_back(num);
            }
        }
        
        return missing;
    }
};
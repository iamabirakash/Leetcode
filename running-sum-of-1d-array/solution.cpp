class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> res;
        for(int it : nums){
            sum += it;
            res.push_back(sum);
        }
        return res;
    }
};
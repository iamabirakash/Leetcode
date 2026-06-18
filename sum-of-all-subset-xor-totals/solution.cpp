class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>& curr,vector<int>& nums,int idx){
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        helper(res,curr,nums,idx+1);
        curr.pop_back();
        helper(res,curr,nums,idx+1);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(res,curr,nums,0);
        int ans = 0;
        for(auto& row : res){
            int xorsum = 0;
            for(auto& ele : row){
                xorsum ^= ele;
            }
            ans += xorsum;
        }
        return ans;
    }
};
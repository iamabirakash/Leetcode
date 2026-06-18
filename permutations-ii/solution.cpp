class Solution {
public:
    void helper(vector<int>& nums,vector<int>& curr,set<vector<int>>& res,int idx,int n){
        if(idx==n){
            res.insert(curr);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            curr.push_back(nums[idx]);
            helper(nums,curr,res,idx+1,n);
            curr.pop_back();
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        set<vector<int>> res;
        helper(nums,curr,res,0,nums.size());
        vector<vector<int>> ans;
        for(auto& it : res){
            ans.push_back(it);
        }
        return ans;

    }
};

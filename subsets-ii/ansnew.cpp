class Solution {
public:
    void getAllSubsets(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& allSubsets) {
        if(i==nums.size()){
            allSubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getAllSubsets(nums,ans,i+1,allSubsets);
        ans.pop_back();
        int idx = i+1;
        while(idx < nums.size() && nums[idx]==nums[idx-1]) idx++;
        getAllSubsets(nums, ans, idx, allSubsets);
        // if(index == nums.size()){
        //     res.insert(curr);
        //     return;
        // }
        // curr.push_back(nums[index]);
        // makesubsets(nums,curr,res,index+1);
        // curr.pop_back();
        // makesubsets(nums,curr,res,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // vector<int> curr;
        // set<vector<int>> res;
        // makesubsets(nums,curr,res,0);
        // return vector<vector<int>>(res.begin(),res.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums,ans,0,allSubsets);
        return allSubsets;
    }
};
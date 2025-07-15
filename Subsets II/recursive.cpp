class Solution {
public:
    void makesubsets(vector<int>& nums,vector<int>& curr,set<vector<int>>& res,int index) {
        if(index == nums.size()){
            res.insert(curr);
            return;
        }
        curr.push_back(nums[index]);
        makesubsets(nums,curr,res,index+1);
        curr.pop_back();
        makesubsets(nums,curr,res,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        set<vector<int>> res;
        makesubsets(nums,curr,res,0);
        return vector<vector<int>>(res.begin(),res.end());
    }
};

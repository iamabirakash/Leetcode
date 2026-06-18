class Solution {
public:
    void helper(vector<int>& candidates,vector<int>& curr,vector<vector<int>>& ans,int idx,int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]<=target){
                curr.push_back(candidates[i]);
                helper(candidates,curr,ans,i,target-candidates[i]);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(candidates,curr,ans,0,target);
        return ans;
    }
};
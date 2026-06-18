class Solution {
public:
    void helper(vector<int>& candidates,vector<int>& curr,set<vector<int>>& ans,int idx,int target){
        if(target==0){
            ans.insert(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target){
                curr.push_back(candidates[i]);
                helper(candidates,curr,ans,i+1,target-candidates[i]);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        set<vector<int>> ans;
        helper(candidates,curr,ans,0,target);
        vector<vector<int>> result;
        for(auto& combination : ans) {
            result.push_back(combination);
        }
        return result;
    }
};
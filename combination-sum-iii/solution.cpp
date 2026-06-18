class Solution {
public:
    void helper(vector<vector<int>>& res,vector<int>& curr,int k,int n,int idx){
        if(curr.size()==k && n==0){
            res.push_back(curr);
            return;
        }
        if(curr.size()==k || n<0) {
            return;
        }
        for(int i=idx;i<=9 && i<=n;i++){
            curr.push_back(i);
            helper(res,curr,k,n-i,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(res,curr,k,n,1);
        return res;
    }
};
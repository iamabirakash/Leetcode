class Solution {
public:
    void helper(vector<int> & curr,vector<vector<int>>& res,int start,int n,int k){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            helper(curr,res,i+1,n,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(curr,res,1,n,k);
        return res;
    }
    // void helper(vector<int> & curr,vector<vector<int>>& res,int idx,int n,int k){
    //     if(idx==k){
    //         res.push_back(curr);
    //         return;
    //     }
    //     int start = curr.empty()? 1:curr.back()+1;
    //     for(int i=start;i<=n;i++){
    //         curr.push_back(i);
    //         helper(curr,res,idx+1,n,k);
    //         curr.pop_back();
    //     }
    // }
    // vector<vector<int>> combine(int n, int k) {
    //     vector<int> curr;
    //     vector<vector<int>> res;
    //     helper(curr,res,0,n,k);
    //     return res;
    // }
};
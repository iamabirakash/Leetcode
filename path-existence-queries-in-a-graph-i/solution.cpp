class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n,0);
        int compNo = 0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                compNo++;
            }
            component[i] = compNo;
        }
        vector<bool> sol;
        for(auto &it : queries){
            sol.push_back(component[it[0]] == component[it[1]]);
        }
        return sol;
    }
};
// class Solution {
// public:
//     vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
//         // int n = queries.size();
//         vector<bool> res;
//         for(int i=0;i<n;i++){
//             int a = queries[i][0];
//             int b = queries[i][1];
//             if(abs(nums[a]-nums[b])<=maxDiff) res.push_back(true);
//             else {
                
//             }
//         }
//         return res;
//     }
// };
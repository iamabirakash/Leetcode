class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);

        unordered_map<int, vector<int>> mp;

        // Step 1: Store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: Process each group
        for (auto &it : mp) {
            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> prefix(m, 0);

            // Prefix sum of indices
            prefix[0] = v[0];
            for (int i = 1; i < m; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;

                if (i > 0) {
                    left = (long long)i * v[i] - prefix[i - 1];
                }

                if (i < m - 1) {
                    right = (prefix[m - 1] - prefix[i]) - (long long)(m - i - 1) * v[i];
                }

                res[v[i]] = left + right;
            }
        }

        return res;
    }
};


// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         int n = nums.size();
//         vector<long long> res;
//         for(int i=0;i<n;i++){
//             long long cnt = 0;
//             for(int j=0;j<n;j++){
//                 if(i!=j){
//                     if(nums[i]==nums[j]){
//                         cnt += abs(j-i);
//                     }
//                 }
//             }
//             res.push_back(cnt);
//         }
//         // res.push_back(0);
//         return res;
//     }
// };
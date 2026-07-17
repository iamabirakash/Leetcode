class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1);
        for (int num : nums) {
            cnt[num]++;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] += cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }
        for (int i = m; i >= 1; i--) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] -= cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans;
        for (long long q : queries) {
            q++;
            int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n = nums.size();
//         vector<int> res;
//         vector<int> ans;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 res.push_back(gcd(nums[i],nums[j]));
//             }
//         }
//         sort(res.begin(),res.end());
//         for(int i=0;i<queries.size();i++){
//             ans.push_back(res[queries[i]]);
//         }
//         return ans;
//     }
// };
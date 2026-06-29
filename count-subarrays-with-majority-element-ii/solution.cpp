class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        int cnt = n;
        long long ans = 0, presum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }
            ans += presum;
        }
        return ans;
    }
    // long long countMajoritySubarrays(vector<int>& nums, int target) {
    //     long long n = nums.size();
    //     long long ans = 0;
    //     for(int i =0;i<n;i++){
    //         long long cnt = 0;
    //         for(int j=i;j<n;j++){
    //             if(nums[j]==target){
    //                 cnt++;
    //             } else {
    //                 cnt--;
    //             }
    //             if(cnt>0) ans++;
    //         }
    //     }
    //     return ans;
    // }
};
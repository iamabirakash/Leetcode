class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=0;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        suffix[n-1]=0;
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = abs(prefix[i]-suffix[i]);
        }
        return ans;
    }
};
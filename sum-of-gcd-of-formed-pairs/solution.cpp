class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> res;
        int maxm = INT_MIN, n = nums.size();
        for(int i=0;i<n;i++){
            maxm = max(maxm,nums[i]);
            int ans = gcd(maxm,nums[i]);
            res.push_back(ans);
        }
        int m = res.size();
        int left=0,right=m-1;
        long long sum = 0;
        sort(res.begin(),res.end());
        while(left<right){
            sum += gcd(res[left],res[right]);
            left++;
            right--;
        }
        return sum;
    }
};
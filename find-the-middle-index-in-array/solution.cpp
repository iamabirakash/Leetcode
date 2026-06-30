class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int leftSum = (i==0)?0:prefix[i-1];
            int rightSum = (i==n-1)?0:suffix[i+1];
            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};
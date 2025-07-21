class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxlen = 0;
        int zeroCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroCount++;
            }
            while(zeroCount>k){
                if(nums[left]==0) zeroCount--;
                left++;
            }
            maxlen = max(maxlen,i-left+1);
        }
        return maxlen;
    }
};

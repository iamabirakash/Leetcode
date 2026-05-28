class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int size = INT_MAX;
        int i=0,j=0;
        while(j<n){
            sum += nums[j];
            while(sum>=target){
                size = min(size,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return size == INT_MAX ? 0 : size;
    }
};
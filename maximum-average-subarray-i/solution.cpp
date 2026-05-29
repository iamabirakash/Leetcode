class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        int i = 0;
        for(i=0;i<k;i++){
            sum += nums[i];
        }
        double maxsum = sum;
        while(i<n){
            sum += nums[i];
            sum -= nums[i-k];
            maxsum = max(maxsum,sum);
            i++;
        }
        return maxsum/k;

    }
};
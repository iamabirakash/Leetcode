class Solution {
public:
double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        double maxm = sum;
        for(int i=k;i<n;i++) {
            sum += nums[i]-nums[i-k];
            maxm = max(maxm, sum);
        }
        return maxm/k;
    }
    // double findMaxAverage(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     double maxm = 0.00000;
    //     if(n==1) return (double)nums[0];
    //     for(int i=0;i<=n-k;i++){
    //         double curmax = 0.00000;
    //         for(int j=0;j<k;j++){
    //             curmax += nums[i+j];
    //         }
    //         maxm = max(maxm,curmax/k);
    //     }
    //     return maxm;
    // }
};
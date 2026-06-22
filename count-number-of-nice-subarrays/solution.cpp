class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, oddCount = 0, result = 0;
        int prefixEven=0;  // Count of even numbers before the first odd in window
        for(int right=0;right<n;right++){
            // If current number is odd
            if(nums[right]%2==1){
                oddCount++;
                prefixEven=0;  // Reset when we find a new odd
            }
            // When we have exactly k odd numbers
            while(oddCount==k){
                // Count consecutive even numbers at the left
                if(nums[left]%2==1){
                    oddCount--;
                }
                prefixEven++;
                left++;
            }
            result += prefixEven;
        }
        return result;
    }
};
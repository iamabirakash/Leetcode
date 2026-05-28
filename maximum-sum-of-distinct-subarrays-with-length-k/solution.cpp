class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;
        
        unordered_map<int, int> mp;
        long long sum = 0, maxsum = 0;
        int dup = 0;
        
        // Process first window
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) {  // First time becoming a duplicate
                dup++;
            }
            sum += nums[i];
        }
        
        if (dup == 0) {
            maxsum = sum;
        }
        
        // Slide the window
        for (int i = k; i < n; i++) {
            int add = nums[i];
            int subs = nums[i - k];
            
            // Add new element
            mp[add]++;
            if (mp[add] == 2) {  // Became duplicate
                dup++;
            }
            sum += add;
            
            // Remove old element
            mp[subs]--;
            if (mp[subs] == 1) {  // No longer duplicate
                dup--;
            }
            sum -= subs;
            
            // Update maxsum if no duplicates
            if (dup == 0) {
                maxsum = max(maxsum, sum);
            }
        }
        
        return maxsum;
    }
};

// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int,int> mp;
//         long long sum=0,maxsum=0;
//         int dup = 0;
//         for(int i=0;i<k;i++){
//             mp[nums[i]]++;
//             sum += nums[i];
//             if(mp[nums[i]]>1){
//                 dup++;
//             }
//         }
//         if(dup==0){
//             maxsum = max(maxsum,sum);
//         }
//         for(int i=k;i<n;i++){
//             int add = nums[i];
//             int subs = nums[i-k];
//             mp[add]++;
//             if(mp[add]>1) dup++;
//             sum += add;

//             if(mp[subs]>1) dup--;
//             mp[subs]--;
//             sum -= subs;

//             if(dup==0) sum = max(sum,maxsum);
//         }
//         return sum;
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end()){
                return {mp[remaining],i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int start = 0;
//         int end = 0;
//         int sum = 0;
//         while(sum!=target && start<=end){
//             end++;
//             sum = nums[start]+nums[end];
//             if(sum>target){
//                 start++;
//                 end = start;
//                 sum = 0;
//             }
//         }
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==nums[end]) end = i;
//         }
//         vector<int> dp;
//         dp.push_back(start);
//         dp.push_back(end);
//         return dp;
//     }
// };

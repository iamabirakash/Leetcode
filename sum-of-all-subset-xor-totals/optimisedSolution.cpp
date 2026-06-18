// class Solution {
// public:
//     void helper(vector<vector<int>>&res,vector<int>& curr,vector<int>& nums,int idx){
//         if(idx==nums.size()){
//             res.push_back(curr);
//             return;
//         }
//         curr.push_back(nums[idx]);
//         helper(res,curr,nums,idx+1);
//         curr.pop_back();
//         helper(res,curr,nums,idx+1);
//     }
//     int subsetXORSum(vector<int>& nums) {
//         vector<int> curr;
//         vector<vector<int>> res;
//         helper(res,curr,nums,0);
//         int ans = 0;
//         for(auto& row : res){
//             int xorsum = 0;
//             for(auto& ele : row){
//                 xorsum ^= ele;
//             }
//             ans += xorsum;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void helper(vector<int>& nums, int idx, int currentXOR, int& total) {
        if(idx == nums.size()) {
            total += currentXOR;
            return;
        }
        
        // Include current element
        helper(nums, idx + 1, currentXOR ^ nums[idx], total);
        
        // Exclude current element
        helper(nums, idx + 1, currentXOR, total);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        helper(nums, 0, 0, total);
        return total;
    }
};   
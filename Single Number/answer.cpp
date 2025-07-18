class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mul = 0;
        for(int i=0;i<nums.size();i++){
            mul = mul^nums[i];
        }
        return mul;
    }
};

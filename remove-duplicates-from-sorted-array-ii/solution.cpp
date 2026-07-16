class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int it : nums) mp[it]++;
        int prev = nums[0],n=nums.size(),cnt=0,change=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]<=2) continue;
            else {
                if(prev != nums[i]){
                    prev = nums[i];
                    cnt = 0;
                }
                if(cnt>=2){
                    // mp[nums[i]]--;
                    nums[i]=INT_MAX-1;
                    change++;
                }
                cnt++;
            }
        }
        sort(nums.begin(),nums.end());
        return n-change;
    }
};
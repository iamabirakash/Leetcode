class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            if(nums[i] == nums[i-1]) continue;
            int prev = i-1;
            while(prev>0 && nums[prev]==nums[i]) prev--;
            int next = i + 1;
            while(next<n && nums[next] == nums[i]) next++;
            if(prev<0 || next>=n) continue;
            if(nums[i] > nums[prev] && nums[i] > nums[next]) cnt++;
            else if(nums[i] < nums[prev] && nums[i] < nums[next]) cnt++;
        }
        return cnt;
    }
};

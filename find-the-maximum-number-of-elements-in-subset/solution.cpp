class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int x = 0;
        for(int num:nums) mp[num]++;
        int ans = INT_MIN;
        if(mp[1]>0){
            if(mp[1]%2==0) ans = max(ans,mp[1]-1);
            else ans = max(ans,mp[1]);
        }
        for(auto& it:mp){
            int len = 1;
            if(it.first==1) continue;
            long long x = it.first;
            while(mp.count(x*x)>0 && mp[x]>=2){
                len += 2;
                x = x*x;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};
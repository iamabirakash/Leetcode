class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        int left = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                ans += n-i;
                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};
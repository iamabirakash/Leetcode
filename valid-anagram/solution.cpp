class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(char c:t){
            // if(mp[c]==mp.end()) return true;
            mp[c]--;
            if(mp[c]<0) return false;
        }
        return true;
    }
};
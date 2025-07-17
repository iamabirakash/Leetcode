class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,char> rev;
        for(int i=0;i<s.length();i++){
            auto it = mp.find(s[i]);
            if(it != mp.end()){
                if(it->second!=t[i]) return false;
            } else {
                if (rev.find(t[i]) != rev.end()) return false;
                mp.insert({s[i], t[i]});
                rev.insert({t[i], s[i]});
            }
        }
        return true;
    }
};

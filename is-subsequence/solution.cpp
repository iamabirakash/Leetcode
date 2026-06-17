class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = 0;
        int tt = 0;
        while(ss<s.length() && tt<t.length()){
            if(s[ss]==t[tt]) ss++;
            tt++;
        }
        return ss==s.length();
    }
};
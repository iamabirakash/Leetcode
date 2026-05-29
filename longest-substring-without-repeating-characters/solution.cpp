class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len = 0;
        int i=0,j=0;
        unordered_set<char> ss;
        while(j<n){
            while(ss.find(s[j])!=ss.end()){
                ss.erase(s[i]);
                i++;
            }
            ss.insert(s[j]);
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};
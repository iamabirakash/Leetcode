class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        // Remove first and last character to avoid trivial full-match
        string middle = doubled.substr(1, doubled.size() - 2);
        return middle.find(s) != string::npos;
    }
};      
class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    void makePalindrome(string& s, vector<string>& curr, int index) {
        if (index == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                makePalindrome(s, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        makePalindrome(s, curr, 0);
        return res;
    }
};

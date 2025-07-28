class Solution {
public:
    void func(int idx, string digits, string arr[], vector<string>& ans, string& temp){
        if (digits.empty()) return;
        if(idx==digits.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i<arr[(digits[idx] - '0' )-2].length(); i++){
            temp+=arr[(digits[idx] - '0' )-2][i];
            func(idx+1, digits, arr, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string arr[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp = "";
        vector<string> ans;
        func(0, digits, arr, ans, temp);
        return ans;
    }
};

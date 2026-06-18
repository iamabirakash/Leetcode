class Solution {
public:
    vector<string> phoneMap = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    void helper(string& digits,string& curr,vector<string>& res,int idx){
        if(idx==digits.length()){
            res.push_back(curr);
            return;
        }
        int digit = digits[idx]-'0';
        string letters = phoneMap[digit];
        for(char ch : letters) {
            curr.push_back(ch);
            helper(digits,curr,res,idx+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty() || digits=="1") return res;
        string curr = "";
        helper(digits,curr,res,0);
        return res;
    }
};
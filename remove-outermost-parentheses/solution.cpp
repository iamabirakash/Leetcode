class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int cnt = 0;
        int ans = 0;
        string str = "";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt>0) str+='(';
                cnt++;
            }
            else {
                cnt--;
                if(cnt>0) str += ")";
            }
        }
        return str;
    }
};
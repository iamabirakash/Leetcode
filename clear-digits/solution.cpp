class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        string str="";
        stack<char> st;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
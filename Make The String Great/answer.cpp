class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            } else if(st.top()==s[i]+32 || st.top()==s[i]-32){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string ss ="";
        while(!st.empty()){
            ss += st.top();
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;
    }
};

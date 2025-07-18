class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(s[i]==']') {
                string ss = "";
                while(!st.empty() && st.top()!="["){
                    ss = st.top()+ss;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num = st.top()+num;
                    st.pop();
                }
                int a = stoi(num);
                string temp = "";
                for (int i=0;i<a;++i) {
                    temp += ss;
                }
                st.push(temp);
            } else {
                st.push(string(1,s[i]));
            }
        }
        string sss = "";
        while(!st.empty()){
            sss = st.top()+sss;
            st.pop();
        }
        return sss;
    }
};

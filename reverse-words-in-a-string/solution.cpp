class Solution {
public:
    string reverseWords(string s) {
        string ss= "";
        vector<string> a;
        int n = s.length();
        bool started = false;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' ' ){
                ss += s[i];
            } else {
                if(!ss.empty()){
                    reverse(ss.begin(),ss.end());
                    a.push_back(ss);
                    ss = "";
                }
            }
        }
        if (!ss.empty()) {
            reverse(ss.begin(), ss.end());
            a.push_back(ss);
        }
        int nn = a.size();
        string sss = "";
        for(int i=0;i<nn;i++){
            sss += a[i];
            if(i != nn - 1) sss += " ";
        }
        return sss;
    }
};
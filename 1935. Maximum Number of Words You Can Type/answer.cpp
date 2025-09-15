class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> res;
        int x = brokenLetters.length();
        string s = "";
        for(char ch : text){
            if(ch==' '){
                res.push_back(s);
                s = "";
            } else s += ch;
        }
        res.push_back(s);
        int cnt = 0;
        int n = res.size();
        for(int i=0;i<n;i++){
            int m = res[i].length();
            for(int j=0;j<m;j++){
                bool found = false;
                for(int k=0;k<x;k++){
                    if(res[i][j]==brokenLetters[k]){
                        cnt++;
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }
    return n-cnt;
    }
};

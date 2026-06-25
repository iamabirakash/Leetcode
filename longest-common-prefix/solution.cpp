class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].size();
        for(int i=0;i<n;i++){
            int a = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i==strs[j].size() || a!=strs[j][i]) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
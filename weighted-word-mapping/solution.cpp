class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(string word : words){
            int s = 0;
            for(char c : word){
                s += weights[c-'a'];
            }
            ans += 'z'-s%26;
        }
        return ans;
    }
};
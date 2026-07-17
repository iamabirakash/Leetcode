class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int cnt = 0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]-'a'<0) cnt++;
        }
        if(cnt==word.size()||(cnt==1 && word[0]-'a'<0)||cnt==0) return true;
        return false;
    }
};
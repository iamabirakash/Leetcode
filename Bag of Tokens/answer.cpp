class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0,maxScore = 0;
        int l=0,r=n-1;
        while(l<=r){
            if(tokens[l]<=power){
                power -= tokens[l];
                score++;
                l++;
                maxScore = max(score,maxScore);
            } else if(score>0){
                power += tokens[r];
                score--;
                r--;
            } else {
                break;
            }
        }
        return maxScore;
    }
};

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char ch : text){
            mp[ch]++;
        }
        int maxBalloons = INT_MAX;
        maxBalloons = min(maxBalloons, mp['b']);
        maxBalloons = min(maxBalloons, mp['a']);
        maxBalloons = min(maxBalloons, mp['l'] / 2);  // Need 2 'l's
        maxBalloons = min(maxBalloons, mp['o'] / 2);  // Need 2 'o's
        maxBalloons = min(maxBalloons, mp['n']);
        return max(0, maxBalloons);
        // for(auto& it : mp){
        //     minBalloon = min(it.second,minBalloon);
        // }
        // return minBalloon;
    }
};
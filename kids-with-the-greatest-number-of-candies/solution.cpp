class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res;
        int maxCandies = INT_MIN;
        for(int it : candies) maxCandies = max(maxCandies,it);
        for(int it : candies){
            int curr = it + extraCandies;
            if(curr>=maxCandies){
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};
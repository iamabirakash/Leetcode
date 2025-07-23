class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp;
        int buy = 0;
        int sell = 0;
        for(int i=0;i<prices.size();i++){
            if(buy<=sell) {
                buy = min(prices[buy],prices[i]);
                sell = max(prices[sell],prices[i]);
            }
        }
        return (prices[sell]-prices[buy]);
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> res = prices;
        for(int i=0;i<n;i++){
            while(!st.empty() && prices[st.top()]>=prices[i]){
                res[st.top()] = prices[st.top()]-prices[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

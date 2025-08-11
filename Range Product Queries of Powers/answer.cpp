class Solution {
public:
    vector<int> productQueries(int k, vector<vector<int>>& queries) {
        int n = queries.size();
        const int MOD = 1e9 + 7;
        vector<int> powers;
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            if (k & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            int fir = queries[i][0];
            int sec = queries[i][1];
            long long mul = 1;
            for(int j=fir;j<=sec;j++){
                mul = (mul*(long long)powers[j])%MOD; 
            }
            res.push_back((int)mul);
        }
        return res;
    }
};

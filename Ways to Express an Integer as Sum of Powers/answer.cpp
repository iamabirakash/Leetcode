class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(int n, int x) {
        vector<int> ways(n + 1);
        ways[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (pow(i, x) > n) break;
            for (int j = n; j >= 0; --j) {
                int power = pow(i, x);
                if (ways[j] == 0 || j + power > n) continue;
                ways[j + power] = (ways[j + power] + ways[j]) % MOD;
            }
        }
        return ways.back();
    }
};

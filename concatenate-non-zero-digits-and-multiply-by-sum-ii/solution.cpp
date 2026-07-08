class Solution {
private:
    static constexpr int MOD = 1000000007;
    static constexpr int MAX = 100001;
    inline static int pow[MAX];

    inline static int init = []() {
        pow[0] = 1;
        for (int i = 1; i < MAX; i++)
            pow[i] = pow[i - 1] * 10LL % MOD;
        return 0;
    }();

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> A(n + 1, 0);
        vector<int> B(n + 1, 0);
        vector<int> ln(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            A[i + 1] = A[i] + d;
            B[i + 1] = d ? (B[i] * 10LL + d) % MOD : B[i];
            ln[i + 1] = ln[i] + (d > 0);
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1] + 1;

            long long sub = B[l] * 1LL * pow[ln[r] - ln[l]] % MOD;
            long long x = (B[r] - sub + MOD) % MOD;

            res.push_back(x * (A[r] - A[l]) % MOD);
        }

        return res;
    }
};
// class Solution {
// public:
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries){
//         int n = queries.size();
//         int q = queries.size();
//         vector<int> sumSoFar(n+1,0);
//         vector<int> prefix(n+1,0);
//         for(int i=0;i<m;i++){
//             sumSoFar[i+1] = sumSoFar[i];
//             prefix[i+1] = prefix[i];
//             if(s[i]!='0') {
//                 int num = s[i]-'0';
//                 sumSoFar[i+1] = (sumSoFar[i+1] + num)%MOD;
//                 prefix[i+1] = (prefix[i+1]*10 + num)%MOD;
//             }
//         }
//         vector<long long> pow10(n+1,1);
//         for(int i=1;i<=n;i++){
//             pow10[i] = (pow10[i-1]*10)%MOD;
//         }
//         // sumSoFar[0] = 0;
//         // prefix[0] = 0;
//         // for(int i=1;i<n;i++){
//         //     int num = s[i-1]-'0';
//         //     sumSoFar[i] = num+sumSoFar[i-1];
//         //     prefix[i] = prefix[i]*10+num;
//         // }
//         for(int i=0;i<n;i++){
//             int a = queries[i][0];
//             int b = queries[i][1];
//             long long sum = 0; digit=0;
//             sum = (s[b+1]-'0')-(s[a]-'0');
//             digit = (s[b+1]-'0')-(s[a]*pow())
//         }
//     }
//     // vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         // const int MOD = 1000000007;
//         // int n = queries.size();
//         // vector<int> res;
//         // for(int i=0;i<n;i++){
//             // int a = queries[i][0];
//             // int b = queries[i][1];
//             // long long sum = 0,x = 0;
//             // for(int j=a;j<=b;j++){
//                 // if(s[j]!='0'){
//                     // int num = s[j]-'0';
//                     // x = (x*10+num)%MOD;
//                     // sum = (sum+num)%MOD;
//                 // }
//             // }
//             // res.push_back((sum*x)%MOD);
//         // }
//         // return res;
//     // }
// };
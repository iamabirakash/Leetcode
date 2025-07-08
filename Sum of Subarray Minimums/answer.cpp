class Solution {
public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top();
            } else {
                res[i] = -1;
            }
            st.push(i);
        }
        return res;
    }
    vector<int> rightSmaller(vector<int> arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = st.top();
            } else {
                res[i] = n;
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> NSL = leftSmaller(arr);
        vector<int> NSR = rightSmaller(arr);
        long long m = 0;
        for(int i = 0; i < n; i++){
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            m = (m + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
        }
        return (int)m;
    }
};

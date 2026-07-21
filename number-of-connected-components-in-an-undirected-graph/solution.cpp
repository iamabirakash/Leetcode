class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& check, int idx, int n) {
        check[idx] = true;
        for (int next : adj[idx]) {
            if (!check[next]) {
                dfs(adj, check, next, n);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> check(n, false);
        for (int i = 0; i < n; i++) {
            if (!check[i]) {
                dfs(adj,check,i,n);
                cnt++;
            }
        }
        return cnt;
    }
};
// class Solution {
// public:
//     void dfs(vector<vector<int>>& edges,vector<bool>& check,int idx,int n){
//         if(idx>=n) return;
//         check[idx] = true;
//         if(edges[idx][1]) dfs(edges,check,next,n);
//         else return;
//     }
//     int countComponents(int n, vector<vector<int>>& edges) {
//         int cnt = 0;
//         vector<bool> check(n,0);
//         for(int i=0;i<n;i++){
//             if(!check[i]) {
//                 dfs(edges,check,i,n);
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

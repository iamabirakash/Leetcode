class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<bool>& visit,int i,int parent){
        if(visit[i]) return false;
        visit[i] = true;
        for(int it:graph[i]){
            if(it==parent) continue;
            if(visit[it] || !dfs(graph, visit, it, i)) {
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<bool> visit(n,false);
        vector<vector<int>> graph(n);
        for(auto& a:edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        if(!dfs(graph,visit,0,-1)) return false;
        for(bool v : visit){
            if(!v) return false;
        }
        return true;
    }
};

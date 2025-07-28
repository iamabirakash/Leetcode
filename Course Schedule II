class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> list(V);
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            list[u].push_back(v);
        }
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++){
            for(int v : list[i]){
                indeg[v]++;
            }
        }
        
        vector<int> topsort;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topsort.push_back(node);
            
            for(auto it : list[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(topsort.size()!=V) return {};
        reverse(topsort.begin(),topsort.end());
        return topsort;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        int completeCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // BFS/DFS to find component
                queue<int> q;
                q.push(i);
                visited[i] = true;
                vector<int> component;
                
                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    component.push_back(node);
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                // Count edges in this component
                int nodes = component.size();
                int edgesCount = 0;
                for (int node : component) {
                    edgesCount += adj[node].size();
                }
                edgesCount /= 2; // Each edge counted twice
                
                // Check if complete
                if (edgesCount == nodes * (nodes - 1) / 2) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
};
// class Solution {
// public:
//     int countCompleteComponents(int n, vector<vector<int>>& edges) {
//         int m = edges.size();
//         vector<vector<int>> graph(n);
//         for(auto& it : edges){
//             graph[edges[0]].push_back(edges[1]);
//             graph[edges[1]].push_back(edges[0]);
//         }
//         int com = 0;
//         unordered_set<int> visit;
//     }
// };
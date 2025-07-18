class Solution {
public:
    bool cycle(vector<vector<int>>& graph,vector<int>& visit,int i){
        if (visit[i] == 1) return true;
        if (visit[i] == 2) return false;  

        visit[i] = 1;

        for (int a : graph[i]) {
            if (cycle(graph, visit, a)) {
                return true;
            }
        }
        visit[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& a : prerequisites){
            graph[a[1]].push_back(a[0]);
        }
        vector<int> visit(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(cycle(graph,visit,i)){
                return false;
            }
        }
        return true;
    }
};

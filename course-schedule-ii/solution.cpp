class Solution {
public:
    bool dfs(vector<int>& ans,vector<vector<int>>& graph,vector<int>& visit,int i){
        if(visit[i]==1) return true;
        if(visit[i]==2) return false;
        visit[i] = 1;
        for(int next : graph[i]){
            if(dfs(ans,graph,visit,next)){
                return true;
            }
        }
        visit[i] = 2;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> visit(numCourses);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(dfs(ans,graph,visit,i)){
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
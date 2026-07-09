class Solution {
public:
    int maxArea = 0;
    void dfs(int i,int j,vector<vector<bool>>& check,vector<vector<int>>& grid,int& area){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || check[i][j] || grid[i][j]==0){
            return;
        }
        area++;
        check[i][j]=1;
        dfs(i-1,j,check,grid,area);
        dfs(i,j-1,check,grid,area);
        dfs(i+1,j,check,grid,area);
        dfs(i,j+1,check,grid,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n,vector<bool>(m,false));        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            int area = 0;
                if(grid[i][j]==1 && !check[i][j]){
                    dfs(i,j,check,grid,area);
                }
            maxArea = max(area,maxArea);
            }
        }
        return maxArea;
    }
};
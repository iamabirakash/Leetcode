class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int cnt){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]==-1 || grid[i][j]<cnt){
            return;
        }
        if(grid[i][j]==0){
            grid[i][j]=cnt;
        }
        grid[i][j] = cnt;
        dfs(i-1,j,grid,cnt+1);
        dfs(i,j-1,grid,cnt+1);
        dfs(i+1,j,grid,cnt+1);
        dfs(i,j+1,grid,cnt+1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid,0);
                }
            }
        }
    }
};

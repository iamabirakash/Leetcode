class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<int> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result.push_back(grid[i][j]);
            }
        }
        sort(result.begin(),result.end());
        int s = result.size();
        int med = result[s/2];
        for(int num : result){
            if(num%x!=med%x) return -1;
            else {
                res += abs(num-med)/x;
            }
        }
        return res;
    }
};
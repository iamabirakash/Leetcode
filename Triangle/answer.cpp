class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int cnt = 0;
        for(int i=n-2;i>=0;i--){
            // int minm = INT_MAX;
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
            // cnt += minm;
        }
        return triangle[0][0];
    }
};

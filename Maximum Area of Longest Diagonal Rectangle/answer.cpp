class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        double maxD = -1.0;
        int maxI = 0;
        for(int i=0;i<n;i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            double dl = sqrt(l*l+w*w);
            if(dl>maxD) {
                maxD = dl;
                maxI = i;
            } else if (abs(dl - maxD) < 1e-9) {
                int currArea = l * w;
                int maxArea = dimensions[maxI][0] * dimensions[maxI][1];
                if (currArea > maxArea) {
                    maxI = i;
                }
            }
        }
        return dimensions[maxI][0]*dimensions[maxI][1];
    }
};

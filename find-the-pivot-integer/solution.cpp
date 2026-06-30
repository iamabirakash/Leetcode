class Solution {
public:
    int pivotInteger(int n) {
        vector<int> res(n+1);
        res[0]=0;
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += i;
            res[i] = res[i-1]+i;
        }
        for(int i=1;i<=n;i++){
            if(res[i]==(sum-res[i-1])) return i;
        }
        return -1;
    }
};
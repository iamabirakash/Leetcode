class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i=1;i<=n;i++){
            int temp = i;
            int result = 0;
            int cnt = 0;
            while(temp>0){
                if(temp%2==1) cnt++;
                temp /= 2;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
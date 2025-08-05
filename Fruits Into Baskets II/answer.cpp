class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> check(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(!check[j] && fruits[i]<=baskets[j]){
                    check[j] = true;
                    flag = true;
                    break;
                }
            }
            if(!flag) cnt++;
        }
        return cnt;
    }
};

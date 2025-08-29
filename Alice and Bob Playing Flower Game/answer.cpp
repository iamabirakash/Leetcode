class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                if(m%2!=0) ans+=(m-1)/2 + 1;
                else ans+=(m-2)/2+1;
            }
            else{
                if(m%2!=0) ans+=(m-1-2)/2 +1;
                else ans+=(m-2)/2+1;
            }
        }
        return ans;
    }
};

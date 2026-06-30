class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left=1,right=INT_MIN;
        for(int i=0;i<n;i++){
            right = max(right,piles[i]);
        }
        int ans = right;
        while(left<=right){
            int mid = left+(right-left)/2;
            int cnt = 0;
            for(int i=0;i<n;i++){
                int div = piles[i]/mid;
                int rem = piles[i]%mid;
                if(rem == 0){
                    cnt+=div;
                } else {
                    cnt += div+1; 
                }
                if(cnt > h) break;
            }
            // for(int i=0;i<n;i++){
            //     int div = piles[i]/mid;
            //     if(div*mid>=piles[i]){
            //         cnt += div;
            //     } else {
            //         int rem = piles[i]-(div*mid);
            //         cnt += (div+rem);
            //     }
            //     if(cnt>h) break;
            // }
            if(cnt<=h) {
                ans = mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int arrangeCoins(int n){
        long long l=1,r=n;
        while(l<=r){
            long long mid = (l+r)/2;
            long long sum = (mid*(mid+1))/2;
            if(n==sum) return mid;
            else if(sum<n) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
    // int arrangeCoins(int n){
    //     int rem = n;
    //     int height = 0;
    //     while(rem>=height+1){
    //         height++;
    //         rem -= height;
    //     }
    //     return height;
    // }
    // int arrangeCoins(int n) {
    //     int height = 1;
    //     int i = 0;
    //     bool check = true;
    //     while(check){
    //         n -= height;
    //         i = height;
    //         height++;
    //         if(n<0) check = false;
    //     }
    //     return i-1;
    // }
};
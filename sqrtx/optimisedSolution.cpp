class Solution {
public:
    int mySqrt(int x) {
        // return pow(x,0.5);
        if(x==0) return 0;
        if(x==1) return 1;
        int left = 0, right = x;
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(mid*mid>x){
                right = mid-1;
            } else if(mid*mid<x){
                left = mid+1;
            } else return mid;
        }
        return right;
    }
};
class Solution {
public:
    bool isPowerOfFour(int n) {
        // return n>0 && n&(n-1)&(n-2)==0;
        if(n<=0) return false;
        while(n%4==0){
            n /= 4;
        }
        return n==1;
    }
};

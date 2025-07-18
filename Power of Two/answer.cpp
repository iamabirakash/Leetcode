class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0  ;
        // if(n==1) return true;
        // for(int i=0;i<=n/2;i++){
        //     if((n>>i)==2) return true;
        // }
        // return false;   
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        long long power = 1;
        while(power<n){
            power *= 3;
        }
        return power==n;
    }
};

class Solution {
public:
    int arrangeCoins(int n){
        int rem = n;
        int height = 0;
        while(rem>=height+1){
            height++;
            rem -= height;
        }
        return height;
    }
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
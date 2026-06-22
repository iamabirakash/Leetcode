class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1, sum = 0;
        int temp = n;
        while(temp>0){
            int digit = temp%10;
            pro *= digit;
            sum += digit;
            temp /= 10;
        }
        return (pro-sum);
    }
};
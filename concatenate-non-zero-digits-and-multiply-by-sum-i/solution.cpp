class Solution {
public:
    long long sumAndMultiply(int n) {
         long long num = 0;
        long long place = 1;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                num = digit * place + num;
                place *= 10;
                sum += digit;
            }

            n /= 10;
        }

        return num * sum;
    }
};
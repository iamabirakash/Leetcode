class Solution {
public:
    int myAtoi(string s) {
        long long ss = 0;
        int sign = 1;
        bool started = false;
        for(char ch: s){
            if(!started && ch==' '){
                continue;
            } else if (!started && ch == '+') {
                sign = 1;
                started = true;
            }
            else if(!started && ch=='-'){
                sign = -1;
                started = true;
            } 
            else if(isdigit(ch)){
                started = true;
                int r = ch-'0'; 
                if (ss > (INT_MAX - r) / 10) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }
                ss = ss * 10 + r;
            } else {
                break;
            }
        }
        return ss*sign;
    }
};

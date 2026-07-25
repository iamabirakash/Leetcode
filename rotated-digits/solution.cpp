class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            string s = to_string(i);
            bool check = false;
            bool valid = false;
            for(char ch : s){
                if(ch=='3' || ch=='4' || ch=='7') {
                    check = true;
                    break;
                }
                if(ch=='2' || ch=='5' || ch=='6' || ch=='9'){
                    valid = true;
                }
            }
            if(!check && valid) cnt++;
        }
        return cnt;
    }
};
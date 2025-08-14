class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string res = "";
        for(int i=2;i<n;i++){
            string cursum = "";
            if((num[i]==num[i-1])&&(num[i-1]==num[i-2])){
                cursum += num[i];
                cursum += num[i];
                cursum += num[i];
            }
            res = max(cursum,res);
        }
        return res;
    }
};

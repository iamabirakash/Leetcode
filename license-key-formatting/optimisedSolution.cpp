class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (count == k) {
                    result += '-';
                    count = 0;
                }
                result += toupper(s[i]);
                count++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// class Solution {
// public:
//     string licenseKeyFormatting(string s, int k) {
//         int dash=0,n=s.length();
//         for(char ch : s){
//             if(ch=='-') dash++;
//         }
//         int valid = n-dash;
//         int rem = valid%k;
//         string ss = "";
//         int cnt = 0;
//         for(int i=n-1;i>=0;i--){
//             if(cnt==k){
//                 if(ss.length()!=0) ss+="-";
//                 cnt=0;
//             }
//             if(s[i]!='-'){
//                 ss+=toupper(s[i]);
//                 cnt++;
//             }
//         }
//         int m = ss.length();
//         if(m>0){
//         if(ss[m-1]=='-') ss.pop_back();
//         }
//         reverse(ss.begin(),ss.end());
//         return ss;
//     }
// };
// class Solution {
// public:
//     int carry = 0; 
//     stack<char> st;
//     string addBinary(string a, string b) {
//         int i = a.length() - 1;
//         int j = b.length() - 1;
//         while (i >= 0 || j >= 0 || carry) {
//             int sum = carry;
//             if (i >= 0) sum += a[i--] - '0';
//             if (j >= 0) sum += b[j--] - '0';
//             st.push(sum % 2 + '0');
//             carry = sum / 2;
//         }
//         string res = "";
//         while (!st.empty()) {
//             res += st.top();
//             st.pop();
//         }
//         return res;
//     }
// };
class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int str1Len=a.size() -1;
        int str2Len=b.size() -1;
        int sum=0,carry=0;
        while(str1Len>=0 || str2Len>=0 || carry){
            sum=carry;
            if(str1Len>=0){
                sum += a[str1Len] -'0';
                str1Len --;
            }
            if(str2Len>=0){
                sum += b[str2Len] -'0';
                str2Len --;
            }

            result+= (sum%2) +'0';
            carry= sum/2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

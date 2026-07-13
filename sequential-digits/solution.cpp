class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        
        // Try all possible starting digits from 1 to 9
        for (int start = 1; start <= 9; start++) {
            int num = start;
            // Extend the number by adding sequential digits
            for (int nextDigit = start + 1; nextDigit <= 9; nextDigit++) {
                num = num * 10 + nextDigit;
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
                if (num > high) {
                    break;
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> res; 
//         string l = to_string(low);
//         string h = to_string(high);
//         int n = l.length();
//         string f = l[0];
//         for(int i=1;i<n;i++){
//             f += f[i-1];
//         }
//         res.push_back(f);
        
//     }
// };
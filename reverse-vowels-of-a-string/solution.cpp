class Solution {
public:
    int isVowel(char ch){
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    string reverseVowels(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        while(left<right){
            while(left<right && !isVowel(s[left])){
                left++;
            }
            while(left<right && !isVowel(s[right])){
                right--;
            }
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};
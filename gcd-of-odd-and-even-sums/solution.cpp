class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n*n;
        int even = n*(n+1);
        int i = 0;
        int div = 0;
        int divi = min(odd,even);
        for(int i=1;i<=divi/2+1;i++){
            if(odd%i==0 && even%i==0){
                div = max(div,i);
            }
        }
        return div;
    }
};
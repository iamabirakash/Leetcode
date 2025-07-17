class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int left = 0;
        int right = 0;
        int cnt = 0;
        while(right<n){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                cnt = max(cnt,right-left+1);
                right++;
            } else {
                st.erase(s[left]);
                left++;
            }
        }
        // for(int i=0;i<n;i++){
        //     if(st.find(s[i]) != st.end()) {
        //         len = 0;
        //         st.clear();
        //     }
        //     st.insert(s[i]);
        //     len++;
            
        //     cnt = max(cnt,len);
        // }
        return cnt;
    }
};

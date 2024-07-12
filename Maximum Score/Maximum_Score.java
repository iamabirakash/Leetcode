class Solution {
    public int maximumGain(String s, int x, int y) {
        int ans = 0;
        
        // Prioritize the higher point removal
        if (x > y) {
            ans += compute(s, 'a', 'b', x, y);
        } else {
            ans += compute(s, 'b', 'a', y, x);
        }
        
        return ans;
    }
    
    private int compute(String s, char first, char sec, int highpoints, int lowpoints) {
        int ans = 0;
        Stack<Character> st = new Stack<>();
        
        // First pass: remove higher point substrings
        for (char ch : s.toCharArray()) {
            if (!st.isEmpty() && st.peek() == first && ch == sec) {
                ans += highpoints;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        
        // Prepare for second pass by reversing remaining string
        StringBuilder str = new StringBuilder();
        while (!st.isEmpty()) {
            str.append(st.pop());
        }
        String s1 = str.reverse().toString();
        st.clear(); // clear stack contents
        
        // Second pass: remove lower point substrings
        for (char ch : s1.toCharArray()) {
            if (!st.isEmpty() && st.peek() == sec && ch == first) {
                ans += lowpoints;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return ans;
    }
}

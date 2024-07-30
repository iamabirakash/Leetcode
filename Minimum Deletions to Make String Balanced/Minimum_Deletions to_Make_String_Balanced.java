class Solution {
    public int minimumDeletions(String s) {
        char[] letters = s.toCharArray();
        int aCount = 0;
        int bCount = 0;
        int output = Integer.MAX_VALUE;
        for (int i = 0; i < letters.length; i++)
            aCount += ('b' - letters[i]);

        for (int i = 0; i < s.length(); i++)
        {
            output = Math.min(output, aCount + bCount);
            aCount -= ('b' - letters[i]);
            bCount += (letters[i] - 'a');
        }

        output = Math.min(output, aCount + bCount);
        return output;
    }
}

// class Solution {
//     public int minimumDeletions(String s) {
//         int cnt=0;
//         Stack<Character> st = new Stack<>();
//         for(int i = s.length()-1; i>=0; i--){
//             if(st.isEmpty())
//             st.push(s.charAt(i));
            
//             else if (!st.isEmpty() && s.charAt(i)=='b' && st.peek()=='a') {
//              st.pop();   
//                 cnt++;
//             } else {
//                 st.push(s.charAt(i));
//             }
        
//         }
//     return cnt;
//     }
// }

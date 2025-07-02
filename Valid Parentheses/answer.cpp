class Solution {
    public boolean isValid(String s) {
        Stack<Character> ss = new Stack<>();
        if(s.length()<=1){
            return false;
        }
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='[' ||s.charAt(i)=='{'){
                ss.push(s.charAt(i));
            } else {
                if((ss.empty()) && (s.charAt(i)==']' || s.charAt(i)==')' || s.charAt(i)=='}')){
                    return false;
                }
                if((ss.peek()=='[' && s.charAt(i)==']') || (ss.peek()=='(' && s.charAt(i)==')') || (ss.peek()=='{' && s.charAt(i)=='}')){
                    ss.pop();
                } 
                else {
                    return false;
                }
            }
        }
        if(ss.empty()){
            return true;
        }
        return false;
    }
}

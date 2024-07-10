class Solution {
    public int minOperations(String[] logs) {
        int cnt = 0;
        String c = "../";
        for(String str : logs){
            if(str.equals(c)){
                cnt--;
            } else if(str.equals("./")){
                continue;
            } else {
                cnt++;
            }
        if(cnt<0 || cnt==0){
            cnt = 0;
        }
        }
        return cnt;
    }
}

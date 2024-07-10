class Solution {
    public int passThePillow(int n, int time) {
        // fullround = (n-1)*2
        int extraTime = time % ((n-1) * 2); 
        
        if (extraTime < n) {
            return extraTime + 1;
        } else {
            return n - (extraTime % (n-1));
        }
    }
}

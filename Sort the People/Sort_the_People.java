class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        HashMap<Integer,String> hm = new HashMap<>();
        int i = 0;
        int j = 0;
        String[] res = new String[names.length];
        while(i < heights.length && j < names.length){
            hm.put(heights[i],names[j]);
            i++;
            j++;
        }
        Arrays.sort(heights);
        int y = 0;
        for(int x = heights.length-1; x>=0; x--){
            res[y] = hm.get(heights[x]);
            y++;
        }
        return res;
    }
}
class Solution {
    public static int where;
    
    public static String countOfAtoms(String str){
        where = 0;
        StringBuilder ans = new StringBuilder();
        TreeMap<String, Integer> map = f(str.toCharArray(), 0);
        for (String key : map.keySet()){
            ans.append(key);
            if (map.get(key) > 1){
                ans.append(map.get(key));
            }
        }
        return ans.toString();
    }

    public static void fill(TreeMap<String, Integer> ans, StringBuilder name, TreeMap<String, Integer> pre, int cnt){
        if (name.length() != 0 || pre != null){
            cnt = cnt == 0 ? 1 : cnt;
            if (name.length() > 0){
                String key = name.toString();
                ans.put(key, ans.getOrDefault(key, 0) + cnt);
            } else {
                for (String key: pre.keySet()){
                    ans.put(key, ans.getOrDefault(key, 0) + cnt * pre.get(key));
                }
            }
        }
    }

    public static TreeMap<String, Integer> f(char[] s, int i){
        int cur = 0;
        TreeMap<String, Integer> ans = new TreeMap<>();
        StringBuilder name = new StringBuilder();
        TreeMap<String, Integer> pre = null;

        while (i < s.length && s[i] != ')'){
            if (s[i] == '(' || (s[i] >= 'A' && s[i] <= 'Z')){
                fill(ans, name, pre, cur);
                cur = 0;
                pre = null;
                name.setLength(0);

                if (s[i] == '('){
                    pre = f(s, i + 1);
                    i = where + 1;
                } else {
                    name.append(s[i++]);
                }

            } else if (s[i] - '0' >= 0 && s[i] - '0' <= 9){
                cur = cur * 10 + s[i++] - '0';
            } else {
                name.append(s[i++]);
            }
        }
        where = i;
        fill(ans, name, pre, cur);
        return ans;
    }
}

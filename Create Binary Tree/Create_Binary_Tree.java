class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        //  HashMap<Integer, TreeNode> hm = new HashMap<Integer,TreeNode>();
        // ArrayList<Integer> ls = new ArrayList<Integer>();
        // int l = descriptions.length;
        // for(int i=0;i<l;i++)
        // {
        //     TreeNode tm = hm.getOrDefault(descriptions[i][0],null);
        //     if(tm==null)
        //         hm.put(descriptions[i][0],new TreeNode(descriptions[i][0]));
        //     tm = hm.getOrDefault(descriptions[i][1],null);
        //     if(tm==null)
        //         hm.put(descriptions[i][1],new TreeNode(descriptions[i][1]));

        //     if(descriptions[i][2]==1)
        //     {
        //         hm.get(descriptions[i][0]).left = hm.get(descriptions[i][1]);
        //     }
        //     else{
        //         hm.get(descriptions[i][0]).right = hm.get(descriptions[i][1]);
        //     }
        //     ls.add(descriptions[i][1]);
        // }
        // for (Map.Entry<Integer,TreeNode> mapElement : hm.entrySet()) {
        //     Integer key = mapElement.getKey();
        //     if(!ls.contains(key))
        //     {
        //         System.out.println(hm.get(key) +" "+ key);
        //         return hm.get(key);
                
        //     }
        // }
        // return null;

        final TreeNode[] nodes = new TreeNode[100001];
        final boolean[] children = new boolean[100001];

        for(final int[] description : descriptions) {
            if(nodes[description[0]] == null)
                nodes[description[0]] = new TreeNode(description[0]);

            if(nodes[description[1]] == null)
                nodes[description[1]] = new TreeNode(description[1]);

            if(description[2] == 0)
                nodes[description[0]].right = nodes[description[1]];
            else
                nodes[description[0]].left = nodes[description[1]];

            children[description[1]] = true;
        }

        for(final int[] description : descriptions)
            if(!children[description[0]])
                return nodes[description[0]];

        return null;
    }
}

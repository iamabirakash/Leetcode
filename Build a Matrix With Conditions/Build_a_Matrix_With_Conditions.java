
class Solution {
    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        List<Integer>[] rowGraph = new ArrayList[k + 1]; 
        for(int i = 1 ; i < rowGraph.length; i ++) {
            rowGraph[i] = new ArrayList();
        }
        for(int [] rowCondition : rowConditions){ 
            rowGraph[rowCondition[0]].add(rowCondition[1]); 
        }

        List<Integer>[] colGraph = new ArrayList[k + 1]; 
        for(int i = 1 ; i < colGraph.length; i ++) {
            colGraph[i] = new ArrayList();
        }
        for(int [] colCondition : colConditions){
            colGraph[colCondition[0]].add(colCondition[1]); 
        }

        int[] visited = new int[k + 1];
        Deque<Integer> queue = new LinkedList<>(); 
        for(int i = 1; i < rowGraph.length; i++){ 
            if(!topSort(rowGraph, i, visited, queue)){
                return new int[0][0];
            }
        }

        
        int[] rowOrder = new int[k];
        int[] rowIndexMap = new int[k + 1]; 
        for(int i = 0; i < k; i++){ 
            int node = queue.pollLast(); 
            rowOrder[i] = node; //
            rowIndexMap[node] = i;
        }

        visited = new int[k + 1];
        queue = new LinkedList();
        for(int i = 1; i < colGraph.length; i++){
            if(!topSort(colGraph, i, visited, queue)){
                return new int[0][0];
            }
        }

        int[] colOrder = new int[k];
        int[] colIndexMap = new int[k+1];
        for(int i = 0; i < k; i++){
            int node = queue.pollLast();
            colOrder[i] = node;
            colIndexMap[node] = i;
        }

        int[][] result = new int[k][k];
        
        for(int i = 1; i <= k; i++){
            result[rowIndexMap[i]][colIndexMap[i]] = i;
        }

        return result;

    }

    public boolean topSort(List<Integer>[] graph, int node, int[] visited, Deque<Integer> queue){
        if(visited[node] == 2) {
            return false;
        }
        if(visited[node] == 0){
            visited[node] = 2;
            for(int child : graph[node]){
                if(!topSort(graph, child, visited, queue)){
                    return false;
                }
            }
            visited[node] = 1;
            queue.add(node);
        }
        return true;
    }
}

// class Solution {
//     public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
//         List<Integer> row_sorting = topo_sort(rowConditions, k);
//         List<Integer> col_sorting = topo_sort(colConditions, k);
//         if (row_sorting.isEmpty() || col_sorting.isEmpty())
//             return new int[0][0];

//         Map<Integer, int[]> value_position = new HashMap<>();
//         for (int n = 1; n <= k; ++n) {
//             value_position.put(n, new int[2]);  // element -> [row_index, col_index]
//         }
//         for (int ind = 0; ind < row_sorting.size(); ++ind) {
//             value_position.get(row_sorting.get(ind))[0] = ind;
//         }
//         for (int ind = 0; ind < col_sorting.size(); ++ind) {
//             value_position.get(col_sorting.get(ind))[1] = ind;
//         }

//         int[][] res = new int[k][k];
//         for (int value = 1; value <= k; ++value) {
//             int row = value_position.get(value)[0];
//             int column = value_position.get(value)[1];
//             res[row][column] = value;
//         }

//         return res;
//     }

//     // return True if all okay and return False if cycle was found
//     private boolean dfs(int src, Map<Integer, List<Integer>> graph, Set<Integer> visited, Set<Integer> cur_path, List<Integer> res) {
//         if (cur_path.contains(src)) return false;  // cycle detected
//         if (visited.contains(src)) return true;  // all okay, but we've already visited this node

//         visited.add(src);
//         cur_path.add(src);

//         for (int neighbor : graph.getOrDefault(src, Collections.emptyList())) {
//             if (!dfs(neighbor, graph, visited, cur_path, res))  // if any child returns false
//                 return false;
//         }

//         cur_path.remove(src);  // backtrack path
//         res.add(src);
//         return true;
//     }

//     // if there will be cycle - return empty array, in other case return 1d array as described above
//     private List<Integer> topo_sort(int[][] edges, int k) {
//         Map<Integer, List<Integer>> graph = new HashMap<>();
//         for (int[] edge : edges) {
//             graph.computeIfAbsent(edge[0], x -> new ArrayList<>()).add(edge[1]);
//         }

//         Set<Integer> visited = new HashSet<>();
//         Set<Integer> cur_path = new HashSet<>();
//         List<Integer> res = new ArrayList<>();

//         for (int src = 1; src <= k; ++src) {
//             if (!dfs(src, graph, visited, cur_path, res))
//                 return Collections.emptyList();
//         }

//         Collections.reverse(res);  // we will have res as reversed so we need to reverse it one more time
//         return res;
//     }
// }
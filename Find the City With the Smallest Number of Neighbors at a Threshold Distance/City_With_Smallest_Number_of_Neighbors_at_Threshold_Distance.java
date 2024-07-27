class Solution {
    public int findTheCity(int n, int[][] edges, int thresh) {
        // floyd warshall - O(n^3)
        int max = Integer.MAX_VALUE;
        int [][] graph = new int[n][n];
        
// initialize the graph with maximum values
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++ )
                if( i != j )
                    graph[i][j] = max;

//initialize it with the edge weights provided
        for(int e[] : edges){
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }

// printing that graph
       for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++ ){
                if (graph[i][j] == max) 
                    System.out.print("INF\t");
                else
                    System.out.print(graph[i][j] +"\t");
            }
            System.out.println();
        }            
        System.out.println();

//checking for minimum edges between all the nodes
        for(int i = 0; i < n; i ++ )
            for(int j = 0; j < n; j ++)
                for(int k = 0; k < n; k ++ )
                    if(graph[j][i] != max && graph[i][k] != max)
                        graph[j][k] = Math.min(graph[j][k], graph[j][i] + graph[i][k]);

//printing that graph
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++ ){
                if (graph[i][j] == max) 
                    System.out.print("INF\t");
                else
                    System.out.print(graph[i][j] +"\t");
            }
            System.out.println();
        }

//finding the city with minimum number of cities with paths at most = threshold value
        int node = 0;
        for(int i = 0; i < n; i ++){
            int c = 0; // counting the number of cities
            for(int j = 0; j < n; j ++ ){
                if(graph[i][j] <= thresh)
                    c ++;
            }
            if( c <= max ){
                node = i;
                max = c;
            }
        }
        return node;
    }
}
// Return the city with the smallest number of cities that are reachable through some path 
// and whose distance is at most distanceThreshold.
// If there are multiple such cities, return the city with the greatest number.

// 0	3	INF	INF	
// 3	0	1	4	
// INF	1	0	1	
// INF	4	1	0	

// 0	3	INF	INF	
// 3	0	1	4	
// INF	1	0	1	
// INF	4	1	0	

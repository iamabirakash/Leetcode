class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int n = rowSum.length, m = colSum.length;
        int[][] result = new int[n][m];

        for (int i = 0; i < Math.min(n, m); i++) {
            result[i][i] = Math.min(rowSum[i], colSum[i]);
            rowSum[i] -= result[i][i];
            colSum[i] -= result[i][i];
        }

        for (int i = 0; i < n; i++) {
            if (rowSum[i] > 0) {
                for (int j = 0; j < m; j++) {
                    if (i != j && colSum[j] > 0) {
                        int minValue = Math.min(rowSum[i], colSum[j]);
                        result[i][j] = minValue;
                        rowSum[i] -= minValue;
                        colSum[j] -= minValue;
                    }
                }
            }
        }

        return result;
    }

    //  public int[][] restoreMatrix(int[] r, int[] c) {
    //     int m = r.length;
    //     int n = c.length;
    //     int[][] a = new int[m][n];
    //     int i = m-1;
    //     int j = n-1;
    //     while(i >= 0 && j >= 0){
    //         if(r[i] <= c[j]){
    //             a[i][j] = r[i];
    //             c[j] -= r[i];
    //             i--;
    //         }
    //         else {
    //             a[i][j] = c[j];
    //             r[i] -= c[j];
    //             j--;
    //         }
    //     }
    //     return a;
    // }
}
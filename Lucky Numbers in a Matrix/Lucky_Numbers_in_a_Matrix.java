class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> lsRes = new ArrayList<>();

        for(int i = 0; i < matrix.length; i++)
        {
            int col = findMin(matrix, i);

            int maxCol = matrix[i][col];
            if(maxInCol(matrix, maxCol, col))
                lsRes.add(maxCol);
            // for(int r = 0; r < matrix.length; r++)
            // {
            //     if(matrix[r][col] > maxCol)
            //         maxCol = matrix[r][col];
            // }

            // if(minRow == maxCol)
            //     lsRes.add(matrix[i][col]);
        }

        return lsRes;
    }
    private int findMin(int[][] matrix, int row){
		int val= matrix[row][0], col=0;
		for(int i=1;i<matrix[row].length;i++){
			if(matrix[row][i]<val){
				val=matrix[row][i];
				col=i;
			}
		}
		return col;
	}
    private boolean maxInCol(int[][] matrix, int val, int col){
        for(int i=0;i<matrix.length;i++){
            if(matrix[i][col]>val)
                return false;
        }
        return true;
    }
}

// class Solution {
//     public List<Integer> luckyNumbers (int[][] matrix) {
//         List<Integer> l=new ArrayList<>();
//         int m=matrix.length;
//         int n=matrix[0].length;
//         int minpos=0;
//         for(int i=0;i<m;i++){
//             int min=99999;
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]<min){
//                     min=matrix[i][j];
//                     minpos=j;
//                 }
//             }
//             int max=-999;
//             for(int j=0;j<m;j++){
//                 if(matrix[j][minpos]>max){
//                     max=matrix[j][minpos];
//                 }
//             }
//             if(min==max){
//                 l.add(min);
//             }    
//         }
//         System.gc();
//         return l;
//     }
// }

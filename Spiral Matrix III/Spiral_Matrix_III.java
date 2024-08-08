public final class Solution {

    public static int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int lastRow = rows - 1;
        int lastCol = cols - 1;

        // Allocate space for the coordinates.
        int numCoords = rows * cols;
        int[][] coords = new int[numCoords][];
        int coordIndex = 0;

        // Travel the spiral one loop at a time.
        int row = rStart;
        int col = cStart;
        int numSteps = 1;
        while (coordIndex < numCoords) {
            // Travel east.
            if ((row >= 0) && (row < rows)) {
                int beginCol = Math.max(col, 0);
                col += numSteps;
                int endCol = Math.min(col, cols);
                for (int colIn = beginCol; colIn < endCol; colIn++) {
                    coords[coordIndex++] = new int[] {row, colIn};
                }
            } else {
                col += numSteps;
            }

            // Travel south.
            if ((col >= 0) && (col < cols)) {
                int beginRow = Math.max(row, 0);
                row += numSteps;
                int endRow = Math.min(row, rows);
                for (int rowIn = beginRow; rowIn < endRow; rowIn++) {
                    coords[coordIndex++] = new int[] {rowIn, col};
                }
            } else {
                row += numSteps;
            }
            numSteps++;

            // Travel west.
            if ((row >= 0) && (row < rows)) {
                int beginCol = Math.min(col, lastCol);
                col -= numSteps;
                int endCol = Math.max(col, -1);
                for (int colIn = beginCol; colIn > endCol; colIn--) {
                    coords[coordIndex++] = new int[] {row, colIn};
                }
            } else {
                col -= numSteps;
            }

            // Travel north.
            if ((col >= 0) && (col < cols)) {
                int beginRow = Math.min(row, lastRow);
                row -= numSteps;
                int endRow = Math.max(row, -1);
                for (int rowIn = beginRow; rowIn > endRow; rowIn--) {
                    coords[coordIndex++] = new int[] {rowIn, col};
                }
            } else {
                row -= numSteps;
            }
            numSteps++;
        }
        return coords;
    }
}

class Solution {
    public int numMagicSquaresInside(int[][] grid) {
      int row=grid.length;
      int col=grid[0].length;
      
      //If row and column is less than 3,then there is no magic grid can be formed.
      //Hence we return 0
      if(row<3 || col<3)
      {
        return 0;
      }

      int magicBoxCount=0;
      for(int i=0;i<=row-3;i++)
      {
        for(int j=0;j<=col-3;j++)
        {
            if(isMagicBox(grid,i,j))
              magicBoxCount++;
        }
      }
      return magicBoxCount;


   }

   private boolean isMagicBox(int[][] grid,int i,int j)
   {
      //Center element can only be 5 to get the same sum in diagonal,rows and columns.
      if(grid[i+1][j+1]!=5)
         return false;

      //corner element should not be odd,If any one occurs to be odd,it'll not be able form magicgrid
      if(grid[i][j]%2!=0 || grid[i+2][j]%2!=0 || grid[i][j+2]%2!=0 && grid[i+2][j+2]%2!=0)
        return false;

      //non-corner elements should not even ,it should be odd.
      if(grid[i+1][j]%2==0 || grid[i][j+1]%2==0 || grid[i+1][j+2]%2==0 || grid[i+2][j+1]%2==0)
        return false;
      
      if(grid[i][j]+grid[i][j+1]+grid[i][j+2]!=15 || grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] != 15 ||grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2] != 15)
         return false;
      if(grid[i][j]+grid[i+1][j]+grid[i+2][j] !=15 || grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!= 15 || grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2] !=15)
         return false;
      return true;

      

   }
}

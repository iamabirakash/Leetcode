class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){                  // loop through each row
            bool seen[9]={false};              // track digits in this row
            for(int j=0;j<9;j++){              // loop through columns in the row
                if(board[i][j]=='.'){          // skip empty cells
                    continue ;
                }
                int num=board[i][j]-'1';       // convert char to index 0..8
                if(seen[num]){                 // already seen this digit → invalid
                    return false;
                }
                seen[num]=true;                // mark digit as seen
            }
        }


        for(int j=0;j<9;j++){                  // loop through each column
            bool seen[9]={false};              // track digits in this column
            for(int i=0;i<9;i++){              // loop through rows in the column
                if(board[i][j]=='.'){          // skip empty cells
                    continue ;
                }
                int num=board[i][j]-'1';       // convert char to index 0..8
                if(seen[num]){                 // already seen → invalid
                    return false;
                }
                seen[num]=true ;               // mark as seen
            }
        }


        for(int boxrow=0;boxrow<3;boxrow++){           // loop over 3 box rows
            for(int boxcolumn=0;boxcolumn<3;boxcolumn++){ // loop over 3 box cols
                bool seen[9]={false};                  // track digits in this box
                for(int i=0;i<3;i++){                  // loop inside 3 rows of box
                    for(int j=0;j<3;j++){              // loop inside 3 cols of box
                        int r=boxrow*3+i;              // row index inside box
                        int c=boxcolumn*3+j;           // col index inside box
                        if(board[r][c]=='.'){          // skip empty
                            continue ;
                        }
                        int num=board[r][c]-'1';       // char → 0..8 index
                        if(seen[num]){                 // already seen → invalid
                            return false;
                        }
                        seen[num]=true ;               // mark as seen
                    }
                }
            }
        }
        return true ;
    }
};

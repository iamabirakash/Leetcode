class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column (above current row)
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    void nQueens(vector<vector<string>>& ans,vector<string>& board,int idx,int n,int& cnt){
        if(idx==n){
            ans.push_back(board);
            cnt++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,idx,col,n)){
                board[idx][col] = 'Q';
                nQueens(ans,board,idx+1,n,cnt);
                board[idx][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        if(n==1) return 1;
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        int cnt = 0;
        nQueens(ans,board,0,n,cnt);
        return cnt;
    }
};
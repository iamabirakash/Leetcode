class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int idx) {
        // Base case: found all characters
        if(idx == word.length()) return true;
        // Boundary and constraint checks
        if(row < 0 || row >= board.size() || 
           col < 0 || col >= board[0].size() || 
           board[row][col] != word[idx]) {
            return false;
        }
        // Mark as visited by temporarily changing the character
        char temp = board[row][col];
        board[row][col] = '#';  // Or any character not in the word
        // Explore all 4 directions
        bool found = dfs(board, word, row + 1, col, idx + 1) ||  // Down
                     dfs(board, word, row - 1, col, idx + 1) ||  // Up
                     dfs(board, word, row, col + 1, idx + 1) ||  // Right
                     dfs(board, word, row, col - 1, idx + 1);    // Left
        
        // Backtrack: restore the original character
        board[row][col] = temp;
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // Optimization: If word length > total cells, impossible
        if(word.length() > m * n) return false;
        // Try starting from each cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
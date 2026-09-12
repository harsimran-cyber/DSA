class Solution {
public:

    void dfs(vector<vector<char>>& board, int r, int c) {

        int m = board.size();
        int n = board[0].size();

        // Outside the board
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Only process O
        if (board[r][c] != 'O')
            return;

        // Mark as safe
        board[r][c] = '#';

        // Four directions
        dfs(board, r - 1, c); // up
        dfs(board, r + 1, c); // down
        dfs(board, r, c - 1); // left
        dfs(board, r, c + 1); // right
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // Top and bottom boundaries
        for (int c = 0; c < n; c++) {
            dfs(board, 0, c);
            dfs(board, m - 1, c);
        }

        // Left and right boundaries
        for (int r = 0; r < m; r++) {
            dfs(board, r, 0);
            dfs(board, r, n - 1);
        }

        // Capture surrounded regions
        // and restore safe regions
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
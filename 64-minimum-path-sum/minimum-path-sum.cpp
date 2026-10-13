class Solution {
public:
    int dp(int row, int col, int m, int n,
           vector<vector<int>>& memo,
           vector<vector<int>>& grid) {

        if (row == m - 1 && col == n - 1) {
            return grid[row][col];
        }

        if (memo[row][col] != -1)
            return memo[row][col];

        int right = INT_MAX;
        int down = INT_MAX;

        if (col + 1 < n)
            right = dp(row, col + 1, m, n, memo, grid);

        if (row + 1 < m)
            down = dp(row + 1, col, m, n, memo, grid);

        return memo[row][col] = grid[row][col] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return dp(0, 0, m, n, memo, grid);
    }
};
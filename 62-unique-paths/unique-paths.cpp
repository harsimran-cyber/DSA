class Solution {
public:
    int dp(int row, int col, int m, int n,vector<vector<int>>& memo) {
        if (row == m-1 && col == n-1) {
            return 1;
        }
        if (memo[row][col] != -1)
            return memo[row][col];
        
        int right = 0;
        if (col+1 != n) right = dp(row,col+1,m,n,memo);
        int down = 0;
        if (row+1 != m) down = dp(row+1,col,m,n,memo);

        return memo[row][col] = right + down;
    }


    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dp(0,0,m,n,memo);
    }
};
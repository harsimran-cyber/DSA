class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> ans(m, vector<int>(n, -1));

        // Put all 0s in the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside the grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Already visited
                if (ans[nr][nc] != -1)
                    continue;

                ans[nr][nc] = ans[r][c] + 1;
                q.push({nr, nc});
            }
        }

        return ans;
    }
};
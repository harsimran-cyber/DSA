class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n);

            for (int j = 0; j < n; j++) {

                int down = dp[j];

                int left = INT_MAX;
                int right = INT_MAX;

                if (j > 0) {
                    left = dp[j - 1];
                }

                if (j < n - 1) {
                    right = dp[j + 1];
                }

                curr[j] = matrix[i][j] + min({down, left, right});
            }

            dp = curr;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
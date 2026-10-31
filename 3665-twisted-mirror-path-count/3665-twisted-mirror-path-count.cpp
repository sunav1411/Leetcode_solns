
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<long long> dp(n, 0);
        dp[0] = 1;

        long long res = 0;

        for (int i = 0; i < m; i++) {
            res = 0;

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    // Mirror: exchange incoming directions
                    swap(res, dp[j]);
                }
                else {
                    // Empty cell: combine both paths
                    long long total = (res + dp[j]) % MOD;

                    res = total;
                    dp[j] = total;
                }
            }
        }

        return res;
    }
};
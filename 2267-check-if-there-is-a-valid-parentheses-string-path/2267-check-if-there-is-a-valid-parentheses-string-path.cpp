

class Solution {
    int n,m;
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
        vector<vector<bitset<205>>> dp(n, vector<bitset<205>>(m, 0));
        dp[0][0] = 1ULL << 1;
        auto apply = [](bitset<205> mask, char c) -> bitset<205> {
            return (c == '(') ? (mask << 1) : (mask >> 1);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                bitset<205> merged = 0;
                if (i > 0) merged |= dp[i-1][j];
                if (j > 0) merged |= dp[i][j-1];
                dp[i][j] = apply(merged, grid[i][j]);
            }
        }
        return (dp[n-1][m-1] & (bitset<205>)1) != 0; 
    }
};
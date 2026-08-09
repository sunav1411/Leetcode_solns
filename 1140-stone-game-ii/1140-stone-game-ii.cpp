class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> suffix;

    int solve(int i, int M) {
        if (i >= n) return 0;

        if (2 * M >= n - i) return suffix[i];

        if (dp[i][M] != -1) return dp[i][M];

        int res = 0;
        for (int X = 1; X <= 2 * M; X++) {
            res = max(res, suffix[i] - solve(i + X, max(M, X)));
        }

        return dp[i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));
        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        return solve(0, 1);
    }
};
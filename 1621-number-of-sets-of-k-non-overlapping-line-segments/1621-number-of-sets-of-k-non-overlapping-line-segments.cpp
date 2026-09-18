static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<array<long long, 2>> dp(k + 1, {0, 0});
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = min(i, k); j >= 0; --j) {
                long long p0 = dp[j][0], p1 = dp[j][1];
                long long pj = (j > 0) ? dp[j - 1][1] : 0;
                dp[j][0] = (p0 + pj) % MOD;
                dp[j][1] = (p1 + p0 + pj) % MOD;
            }
        }
        long long ans = dp[k][0];
        if (k > 0) ans = (ans + dp[k - 1][1]) % MOD;
        return (int)ans;
    }
};
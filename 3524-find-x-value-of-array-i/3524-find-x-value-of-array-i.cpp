class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> res(k);
        vector<long long> dp(k, 0);

        for (int i = 0; i < nums.size(); i++) {

            vector<long long> newDp(k, 0);
            newDp[nums[i] % k]++;
            for (int j = 0; j < k; j++) {

                if (dp[j] == 0)
                    continue;

                long long newRemainder =
                    (1LL * j * nums[i]) % k;

                newDp[newRemainder] += dp[j];
            }
            for (int r = 0; r < k; r++) {
                res[r] += newDp[r];
            }
            dp = newDp;
        }

        return res;
    }
};
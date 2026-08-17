class Solution {
public:
    int solve(int i, int j, vector<int>& stoneValue,
              vector<vector<int>>& dp, vector<int>& prefix)
    {
     
        if(i == j)
            return 0;

      
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        for(int k = i; k < j; k++)
        {
            int leftSum;
            if(i == 0)
                leftSum = prefix[k];
            else
                leftSum = prefix[k] - prefix[i - 1];
            int rightSum = prefix[j] - prefix[k];

            int candidate;
            if(leftSum < rightSum)
            {
                candidate = leftSum +
                            solve(i, k, stoneValue, dp, prefix);
            }
            else if(rightSum < leftSum)
            {
                candidate = rightSum +
                            solve(k + 1, j, stoneValue, dp, prefix);
            }
            else
            {
                candidate = leftSum +
                            max(
                                solve(i, k, stoneValue, dp, prefix),
                                solve(k + 1, j, stoneValue, dp, prefix)
                            );
            }

            ans = max(ans, candidate);
        }
        return dp[i][j] = ans;
    }


    int stoneGameV(vector<int>& stoneValue)
    {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        vector<int> prefix(n);

        prefix[0] = stoneValue[0];

        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }
        return solve(0, n - 1, stoneValue, dp, prefix);
    }
};
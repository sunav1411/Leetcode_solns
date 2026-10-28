class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bitset<1024>>> dp(n, vector<bitset<1024>>(m));
        //dp[i][j] = it stores a bitset<1024> {0, 0, 1, 1, 0, .....}

        dp[0][0].set(grid[0][0], 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }

                bitset<1024> up; //[i-1][j]
                bitset<1024> left; //[i][j-1]

                if(i > 0) {
                    up = dp[i-1][j];
                }

                if(j > 0) {
                    left = dp[i][j-1];
                }

                bitset<1024> combined = up | left; //OR operation

                for(int xorVal = 0; xorVal < 1024; xorVal++) {
                    if(combined[xorVal]) {
                        int resultXorVal = xorVal ^ grid[i][j];
                        dp[i][j].set(resultXorVal, 1);
                    }
                }
            }
        }

        //dp[m-1][n-1]
        for(int xorVal = 0; xorVal < 1024; xorVal++) {
            if(dp[n-1][m-1].test(xorVal)) {
                return xorVal;
            }
        }

        return -1;
    }
};
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // Construct the grids.
        vector<vector<int>> grid(n, vector<int>(n, 1));

        for(auto e : mines) {
            grid[e[0]][e[1]] = 0;
        }

        vector<vector<int>> left(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    left[i][j] = ++cnt;
                } else {
                    cnt = 0;
                }
            }
        }

        vector<vector<int>> right(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] == 1) {
                    right[i][j] = ++cnt;
                } else {
                    cnt = 0;
                }
            }
        }

        vector<vector<int>> down(n, vector<int>(n, 0));
        for(int j=0; j<n; j++) {
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(grid[i][j] == 1) {
                    down[i][j] = ++cnt;
                } else {
                    cnt = 0;
                }
            }
        }

        vector<vector<int>> up(n, vector<int>(n, 0));
        for(int j=0; j<n; j++) {
            int cnt = 0;
            for(int i=n-1; i>=0; i--) {
                if(grid[i][j] == 1) {
                    up[i][j] = ++cnt;
                } else {
                    cnt = 0;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int cand1 = min(left[i][j], right[i][j]);
                int cand2 = min(up[i][j], down[i][j]);
                ans = max(ans, min(cand1, cand2));
            }
        }

        return ans;
    }
};
class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int n, int m) {
        vis[r][c] = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == 0 && !vis[nr][nc]) {
                dfs(nr, nc, grid, vis, n, m);
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0 && !vis[i][0])
                dfs(i, 0, grid, vis, n, m);

            if (grid[i][m - 1] == 0 && !vis[i][m - 1])
                dfs(i, m - 1, grid, vis, n, m);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0 && !vis[0][j])
                dfs(0, j, grid, vis, n, m);

            if (grid[n - 1][j] == 0 && !vis[n - 1][j])
                dfs(n - 1, j, grid, vis, n, m);
        }

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }

        return cnt;
    }
};
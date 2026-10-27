class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        grid.reserve(m);

        for (int i = 0; i < m; i++) {
            string row;
            row.reserve(n);
            for (int j = 0; j < n; j++) {
                row += (i == 0 || j == n - 1) ? '.' : '#';
            }
            grid.push_back(row);
        }
        return grid;
    }
};
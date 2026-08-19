class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, char> rows;
        for (int i = 0; i < reservedSeats.size(); ++i) {
            int col = reservedSeats[i][1];
            if (col == 1 || col == 10) {
                continue;
            }
            char val = (char) 1 << (col - 2);
            rows[reservedSeats[i][0]] |= val;
        }
        int res = 0;
        for (auto p : rows) {
            if (((p.second & 0b1111) == 0) ||
                ((p.second & 0b111100) == 0) ||
                ((p.second & 0b11110000) == 0)) {
                res += 1;          
            }
        }
        int val = n - rows.size();
        res += 2 * val;
        return res;
    }
};
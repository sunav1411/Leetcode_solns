class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int rows = 1;
        vector<vector<int>> ans;
        vector<int> prev;

        for(int row = 1; row <= numRows; row++) {
            vector<int> vec(row, 1);
            int i = 0, j = 1;
            while(i+1 < row - 1) {
              vec[j]  = prev[i] + prev[i+1];
              i++; 
              j++;
            }

            ans.push_back(vec);
            prev = vec;
        }

        return ans;
    }
};
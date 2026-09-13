class Solution {
public:
    int largestOverlap(const vector<vector<int>>& img1, const vector<vector<int>>& img2) {
        const int n = img1.size();
        vector<vector<int>> img(3*n-2, vector<int>(3*n-2));
        for(int i = n-1; i < 2*n-1; i++){
            for(int j = n-1; j < 2*n-1; j++){
                img[i][j] = img1[i-n+1][j-n+1];
            }
        }
        int ans = 0;
        for(int i = 0; i < 2*n-1; i++){
            for(int j = 0; j < 2*n-1; j++){
                int count = 0;
                for(int x = 0; x < n; x++){
                    for(int y = 0; y < n; y++){
                        if(img[i+x][j+y] == 1 && img2[x][y] == 1) count++;
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,int k,vector<int> &store,long long &sum){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        sum+=grid[row][col];
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nRow = delRow[i]+row;
            int nCol = delCol[i]+col;
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&!vis[nRow][nCol] && grid[nRow][nCol]!=0){
                dfs(nRow,nCol,grid,vis,k,store,sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        //dfs problem basics
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> store;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum =0;
                if(!vis[i][j] && grid[i][j]!=0){
                    dfs(i,j,grid,vis,k,store,sum);
                    if(sum%k==0){
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
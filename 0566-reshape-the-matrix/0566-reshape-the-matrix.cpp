class Solution{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat,int newRows,int newCols){
        int oldRows=mat.size(),oldCols=mat[0].size();

        if(oldRows*oldCols!=newRows*newCols) return mat;

        vector<vector<int>> res(newRows,vector<int>(newCols));

        for(int r=0;r<oldRows;r++){
            for(int c=0;c<oldCols;c++){
                int pos=r*oldCols+c;
                int nr=pos/newCols,nc=pos%newCols;
                res[nr][nc]=mat[r][c];
            }
        }
        return res;
    }
};
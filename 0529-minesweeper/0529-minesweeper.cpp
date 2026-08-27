class Solution{
public:
    int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    void dfs(vector<vector<char>>& board,int row,int col){
        int m=board.size(),n=board[0].size();
        int mines=0;

        for(int idx=0;idx<8;idx++){
            int nr=row+dir[idx][0],nc=col+dir[idx][1];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&board[nr][nc]=='M')
                mines++;
        }

        if(mines>0) board[row][col]=mines+'0';
        else{
            board[row][col]='B';
            for(int idx=0;idx<8;idx++){
                int nr=row+dir[idx][0],nc=col+dir[idx][1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&board[nr][nc]=='E')
                    dfs(board,nr,nc);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board,vector<int>& click){
        int row=click[0],col=click[1];

        if(board[row][col]=='M'){
            board[row][col]='X';
            return board;
        }

        dfs(board,row,col);
        return board;
    }
};
class Solution{
public:
    bool validTicTacToe(vector<string>& board){
        int zeros=0,cross=0;
        bool winO=false,winX=false;

        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(board[row][col]=='O') zeros++;
                if(board[row][col]=='X') cross++;

                if(zeros>=3){
                    if(board[row][0]=='O'&&board[row][1]=='O'&&board[row][2]=='O') winO=true;
                    if(board[0][col]=='O'&&board[1][col]=='O'&&board[2][col]=='O') winO=true;
                    if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O') winO=true;
                    if(board[2][0]=='O'&&board[1][1]=='O'&&board[0][2]=='O') winO=true;
                }

                if(cross>=3){
                    if(board[row][0]=='X'&&board[row][1]=='X'&&board[row][2]=='X') winX=true;
                    if(board[0][col]=='X'&&board[1][col]=='X'&&board[2][col]=='X') winX=true;
                    if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X') winX=true;
                    if(board[2][0]=='X'&&board[1][1]=='X'&&board[0][2]=='X') winX=true;
                }
            }
        }

        if(winO&&winX) return false;
        if(winX&&zeros==cross) return false;
        if(winO&&cross>zeros) return false;
        if(zeros>cross||cross-zeros>1) return false;

        return true;
    }
};
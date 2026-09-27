class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
      int x=abs(source[0]-target[0]);
        int y=abs(source[1]-target[1]);
        
        if(x==0 && y==0)
        return 0;

        if(x==0 || y==0 || x==y)
        return 1;

        return 2;
    }
};
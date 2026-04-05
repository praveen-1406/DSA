class Solution {
public:
    bool judgeCircle(string moves) {
        int row=0,col=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U')   row--;
            if(moves[i]=='D')   row++;
            if(moves[i]=='L')   col--;
            if(moves[i]=='R')   col++;
        }
        if(row==0 && col==0)    return true;
        return false;
    }
};
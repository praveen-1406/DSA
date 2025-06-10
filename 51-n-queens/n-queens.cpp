class Solution {
public:
    // bool isSafe(int row,int col,vector<string>&board,int n){
    //     int drow=row;
    //     int dcol=col;

    //     while(row>=0 && col>=0){
    //         if(board[row][col]=='Q')    return false;
    //         row--;
    //         col--;
    //     }

    //     row=drow,col=dcol;

    //     while(col>=0){
    //         if(board[row][col]=='Q')    return false;
    //         col--;
    //     }

    //     row=drow,col=dcol;

    //     while(row<n && col>=0){
    //         if(board[row][col]=='Q')    return false;
    //         row++;
    //         col--;
    //     }

    //     return true;

    // }

    // void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    //     if(col==n){
    //         ans.push_back(board);
    //         return;
    //     }

    //     for(int row=0;row<n;row++){
    //         if(isSafe(row,col,board,n)){
    //             board[row][col]='Q';
    //             solve(col+1,board,ans,n);
    //             board[row][col]='.';
    //         }
    //     }
    // }

    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n,vector<int>&upperDiag,vector<int>&lowerDiag,vector<int>&leftRow){
        if(col==n)  {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upperDiag[n-1+col-row]==0 && lowerDiag[row+col]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                upperDiag[n-1+col-row]=1;
                lowerDiag[row+col]=1;

                solve(col+1,ans,board,n,upperDiag,lowerDiag,leftRow);

                board[row][col]='.';
                leftRow[row]=0;
                upperDiag[n-1+col-row]=0;
                lowerDiag[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        vector<int>upperDiag(2*n-1,0);
        vector<int>lowerDiag(2*n-1,0);
        vector<int>leftRow(n,0);

        solve(0,ans,board,n,upperDiag,lowerDiag,leftRow);

        return ans;
    }
};
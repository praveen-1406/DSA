class Solution {
    bool check(int i,int j,vector<vector<int>>& mat){
        for(int row=0;row<mat.size();row++){
            if(mat[row][j]==1 && row!=i)   return false;
        }
        for(int col=0;col<mat[0].size();col++){
            if(mat[i][col]==1 && col!=j)    return false; 
        }
        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int spos=0;
        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                if(mat[row][col]==1 && check(row,col,mat))  spos++;
            }
        }
        return spos;
    }
};
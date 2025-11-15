class Solution {
    // Recursion
    // int f(int row,int col,vector<vector<int>>&grid){
    //     if(row==0 && col==0)  return grid[row][col];
    //     int up=200,left=200;
    //     if(row>0) up=f(row-1,col,grid);
    //     if(col>0) left=f(row,col-1,grid);
    //     return grid[row][col]+min(up,left);   
    // }

    // Memoization
    int f(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row==0 && col==0)  return grid[row][col];
        if(dp[row][col]!=-1)    return dp[row][col];
        int up=INT_MAX,left=INT_MAX;
        if(row>0) up=f(row-1,col,grid,dp);
        if(col>0) left=f(row,col-1,grid,dp);
        return dp[row][col]=grid[row][col]+min(up,left);   
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        // Recursion
        // return f(m-1,n-1,grid);

        // Memoization
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);

    }
};









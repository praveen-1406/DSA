class Solution {
    // Recursion
    // int f(int row,int col,vector<vector<int>>&grid){
    //     if(row<0 || col<0)  return 0;
    //     if(grid[row][col]==1)   return 0;
    //     if(row==0 && col==0 )   return 1;
    //     int up=f(row-1,col,grid);
    //     int left=f(row,col-1,grid);
    //     return up+left;
    // }

    // Memoization
    int f(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(row<0 || col<0)  return 0;
        if(grid[row][col]==1)   return 0;
        if(row==0 && col==0 )   return 1;
        if(dp[row][col]!=-1)    return dp[row][col];
        int up=f(row-1,col,grid,dp);
        int left=f(row,col-1,grid,dp);
        return dp[row][col]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        // Recursion
        // return f(m-1,n-1,grid);

        // Memoization
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);

    }
};
















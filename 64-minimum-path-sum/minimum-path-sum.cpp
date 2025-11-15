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
    // int f(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
    //     if(row==0 && col==0)  return grid[row][col];
    //     if(dp[row][col]!=-1)    return dp[row][col];
    //     int up=INT_MAX,left=INT_MAX;
    //     if(row>0) up=f(row-1,col,grid,dp);
    //     if(col>0) left=f(row,col-1,grid,dp);
    //     return dp[row][col]=grid[row][col]+min(up,left);   
    // }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        // Recursion
        // return f(m-1,n-1,grid);

        // Memoization
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid,dp);

        // Tabulation
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // for(int row=0;row<m;row++){
        //     for(int col=0;col<n;col++){
        //         if(row==0 && col==0)    dp[0][0]=grid[0][0];
        //         else{
        //             int up=INT_MAX,left=INT_MAX;
        //             if(row>0)   up=dp[row-1][col];
        //             if(col>0)   left=dp[row][col-1];
        //             dp[row][col]=grid[row][col]+min(up,left);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization
        vector<int>preRow(n,INT_MAX);
        for(int row=0;row<m;row++){
            vector<int>temp(n,0);
            for(int col=0;col<n;col++){
                if(row==0 && col==0)    temp[col]=grid[0][0];
                else{
                    int up=INT_MAX,left=INT_MAX;
                    up=preRow[col];
                    if(col>0)   left=temp[col-1];
                    temp[col]=grid[row][col]+min(up,left);
                }
            }
            preRow=temp;
        }
        return preRow[n-1];

    }
};









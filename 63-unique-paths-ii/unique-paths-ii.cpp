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
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid,dp);

        // Tabulation
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // dp[0][0]=1;
        // for(int row=0;row<m;row++){
        //     for(int col=0;col<n;col++){
        //         if(grid[row][col]==1)   {
        //             dp[row][col]=0;
        //             continue;
        //         }
        //         if(row==0 && col==0)    continue;
        //         if(col>0 && grid[row][col-1]!=1)   dp[row][col]+=dp[row][col-1];
        //         if(row>0 && grid[row-1][col]!=1)   dp[row][col]+=dp[row-1][col];
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization
        vector<int>preRow(n,0);
        for(int row=0;row<m;row++){
            vector<int>temp(n,0);
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)   {
                    temp[col]=0;
                    continue;
                }
                if(row==0 && col==0){
                    temp[col]=1;
                    continue;
                }
                if(col>0 && grid[row][col-1]!=1)   temp[col]+=temp[col-1];
                if(row>0 && grid[row-1][col]!=1)   temp[col]+=preRow[col];
            }
            preRow=temp;
        }
        return preRow[n-1];

    }
};
















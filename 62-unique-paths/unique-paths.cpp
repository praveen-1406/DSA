class Solution {
    // Memoization
    // int f(int row,int col,int m,int n,vector<vector<int>>&dp){
    //     if(row==m-1 && col==n-1)    return 1;
    //     if(dp[row][col]!=-1)    return dp[row][col];
    //     int cnt=0;
    //     if(col+1 < n)    cnt=cnt+f(row,col+1,m,n,dp);
    //     if(row+1 < m)    cnt=cnt+f(row+1,col,m,n,dp);
    //     return dp[row][col]=cnt;
    // }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(0,0,m,n,dp);

        // tabulation
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0)    continue;
                if(row-1 >=0)    dp[row][col]+=dp[row-1][col];
                if(col-1 >=0)    dp[row][col]+=dp[row][col-1];
            }
        }
        return dp[m-1][n-1];

    }
};
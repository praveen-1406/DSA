class Solution {
    
    // Recursion
    // int f(int row,int col,vector<vector<int>>& mat){
    //     int n=mat.size();
    //     if(row==n-1)    return mat[row][col];
    //     int down=INT_MAX,ldia=INT_MAX,rdia=INT_MAX;
    //     if(col>0)   ldia=mat[row][col]+f(row+1,col-1,mat);
    //     down=mat[row][col]+f(row+1,col,mat);
    //     if(col+1<n) rdia=mat[row][col]+f(row+1,col+1,mat);
    //     return min(down,min(ldia,rdia));
    // }

    // Memoization
    int f(int row,int col,vector<vector<int>>& mat,vector<vector<int>>&dp){
        int n=mat.size();
        if(row==n-1)    return mat[row][col];
        if(dp[row][col]!=-1)    return dp[row][col];
        int down=INT_MAX,ldia=INT_MAX,rdia=INT_MAX;
        if(col>0)   ldia=mat[row][col]+f(row+1,col-1,mat,dp);
        down=mat[row][col]+f(row+1,col,mat,dp);
        if(col+1<n) rdia=mat[row][col]+f(row+1,col+1,mat,dp);
        return dp[row][col]=min(down,min(ldia,rdia));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // Recursion
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,f(0,i,matrix));
        // }
        // return ans;
    
        // Memoization
        // int ans=INT_MAX;
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++){
        //     ans=min(ans,f(0,i,matrix,dp));
        // }
        // return ans;

        // Tabulation
        // vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int i=0;i<n;i++){           // Base Case
        //     dp[n-1][i]=matrix[n-1][i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=n-1;j>=0;j--){
        //         int down=INT_MAX,ldia=INT_MAX,rdia=INT_MAX;
        //         down=dp[i+1][j];
        //         if(j>0) ldia=dp[i+1][j-1];
        //         if(j+1<n)   rdia=dp[i+1][j+1];
        //         dp[i][j]=matrix[i][j]+min(down,min(ldia,rdia));
        //     }
        // }
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,dp[0][i]);
        // }
        // return ans;

        // Space Optimization
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){           // Base Case
            dp[i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n);
            for(int j=n-1;j>=0;j--){
                int down=INT_MAX,ldia=INT_MAX,rdia=INT_MAX;
                down=dp[j];
                if(j>0) ldia=dp[j-1];
                if(j+1<n)   rdia=dp[j+1];
                temp[j]=matrix[i][j]+min(down,min(ldia,rdia));
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i]);
        }
        return ans;

    }
};




















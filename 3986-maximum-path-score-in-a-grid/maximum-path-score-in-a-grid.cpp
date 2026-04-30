class Solution {
    // int f(int i,int j,vector<vector<int>>& grid, int k ,vector<vector<vector<int>>>&dp){
        
    //     if(k<0) return -1;
    //     if(i==grid.size()-1 && j==grid[0].size()-1){
    //         return 0;
    //     }
    //     if(dp[i][j][k]!=-1)    return dp[i][j][k];
    //     int right=-1,down=-1;
    //     if(j<grid[0].size()-1)  right=f(i,j+1,grid,k-(grid[i][j+1]==0?0:1),dp);
    //     if(i<grid.size()-1)     down=f(i+1,j,grid,k-(grid[i+1][j]==0?0:1),dp);
    //     if(right==-1 && down==-1)   return -1;
    //     int maxi=INT_MIN;
    //     if(right!=-1)   maxi=max(maxi,grid[i][j+1]+right);
    //     if(down!=-1)    maxi=max(maxi,grid[i+1][j]+down);
    //     return dp[i][j][k]= maxi;
    // }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        // return f(0,0,grid,k,dp);

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m,vector<int>(k+1,-1)));
        for(int i=0;i<=k;i++){
            dp[n-1][m-1][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i == n-1 && j == m-1) continue;
                for(int cost=k;cost>=0;cost--){
                    int right=-1,down=-1;
                    if(j<grid[0].size()-1 && cost>=(grid[i][j+1]==0?0:1))  right=dp[i][j+1][cost-(grid[i][j+1]==0?0:1)];
                    if(i<grid.size()-1 && cost>=(grid[i+1][j]==0?0:1))     down=dp[i+1][j][cost-(grid[i+1][j]==0?0:1)];
                    if(right==-1 && down==-1)   dp[i][j][cost]= -1;
                    else{
                        int maxi=INT_MIN;
                        if(right!=-1)   maxi=max(maxi,grid[i][j+1]+right);
                        if(down!=-1)    maxi=max(maxi,grid[i+1][j]+down);
                        dp[i][j][cost]= maxi;
                    }
                    
                }
            }
        }
        return dp[0][0][k];
    }
};
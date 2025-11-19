class Solution {

    // Recursion
    // int f(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     if(j1<0 || j2<0 || j1>=m || j2>=m)  return -1e9;
    //     if(i==n-1){
    //         if(j1==j2)  return grid[i][j1];
    //         else    return grid[i][j1]+grid[i][j2];
    //     }
    //     int maxi=0;
    //     for(int d1=-1;d1<=1;d1++){
    //         for(int d2=-1;d2<=1;d2++){
    //             if(j1==j2)  maxi=max(maxi,grid[i][j1]+f(i+1,j1+d1,j2+d2,grid,dp));
    //             else    maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+d1,j2+d2,grid,dp));
    //         }
    //     }
    //     return maxi;
    // }

    // Memoization
    // int f(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     if(j1<0 || j2<0 || j1>=m || j2>=m)  return -1e9;
    //     if(i==n-1){
    //         if(j1==j2)  return grid[i][j1];
    //         else    return grid[i][j1]+grid[i][j2];
    //     }
    //     if(dp[i][j1][j2]!=-1)   return dp[i][j1][j2];
    //     int maxi=0;
    //     for(int d1=-1;d1<=1;d1++){
    //         for(int d2=-1;d2<=1;d2++){
    //             if(j1==j2)  maxi=max(maxi,grid[i][j1]+f(i+1,j1+d1,j2+d2,grid,dp));
    //             else    maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+d1,j2+d2,grid,dp));
    //         }
    //     }
    //     return dp[i][j1][j2]=maxi;
    // }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // return f(0,0,m-1,grid,dp);

        // Tabulation
        // for(int j1=0;j1<m;j1++){
        //     for(int j2=0;j2<m;j2++){
        //         if(j1==j2)  dp[n-1][j1][j2]=grid[n-1][j1];
        //         else        dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        //     }
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j1=0;j1<m;j1++){
        //         for(int j2=0;j2<m;j2++){
        //                 int maxi=-1e8;
        //                 for(int d1=-1;d1<=1;d1++){
        //                     for(int d2=-1;d2<=1;d2++){
        //                         int value=0;
        //                         if(j1==j2)  value=grid[i][j1];
        //                         else    value=grid[i][j1]+grid[i][j2];
        //                         if(j1+d1>=0 && j2+d2>=0 && j1+d1<m && j2+d2<m){
        //                             value+=dp[i+1][j1+d1][j2+d2];
        //                         }
        //                         maxi=max(maxi,value);
        //                     }
        //                 }
        //                 dp[i][j1][j2]=maxi;
        //         }
        //     }
        // }
        // return dp[0][0][m-1];
       
        // Space Optimization
        vector<vector<int>>front(m,vector<int>(m,-1));
        vector<vector<int>>cur(m,vector<int>(m,-1));

        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2)  front[j1][j2]=grid[n-1][j1];
                else        front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                        int maxi=-1e8;
                        for(int d1=-1;d1<=1;d1++){
                            for(int d2=-1;d2<=1;d2++){
                                int value=0;
                                if(j1==j2)  value=grid[i][j1];
                                else    value=grid[i][j1]+grid[i][j2];
                                if(j1+d1>=0 && j2+d2>=0 && j1+d1<m && j2+d2<m){
                                    value+=front[j1+d1][j2+d2];
                                }
                                maxi=max(maxi,value);
                            }
                        }
                        cur[j1][j2]=maxi;
                }
            }
            front=cur;
        }
        return front[0][m-1];
       
    }
};


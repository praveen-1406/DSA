

class Solution {
    // int f(int row,int col,vector<vector<int>>&tri,vector<vector<int>>&dp){
    //     int m=tri.size();
    //     if(row==m-1) return tri[row][col];
    //     if(dp[row][col]!=-1) return dp[row][col];

    //     int down = f(row+1,col,tri,dp);
    //     int dright = f(row+1,col+1,tri,dp);

    //     return dp[row][col] = tri[row][col] + min(down, dright);
    // }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        // create dp with -1
        // vector<vector<int>> dp(m,vector<int>(m,-1));
        // for(int i = 0; i < m; ++i) dp[i] = vector<int>(i+1, -1);

        // return f(0,0,triangle,dp);

        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
                vector<int>temp(n,-1);
                for(int j=0;j<=i;j++){
                        if(i==0 && j==0)        temp[0]=triangle[0][0];
                        else{
                                int up=INT_MAX,uleft=INT_MAX;
                                if(j!=i)        up=dp[j];
                                if(j>0)         uleft=dp[j-1];
                                temp[j]=triangle[i][j]+min(up,uleft);
                        }
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

class Solution {
    int f(int i,int j,string &s,string &t,int len,vector<vector<int>>&dp){
        if(i==0 || j==0){
            if(j==0)   return 1;
            return 0;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans=0;
        if(s[i-1]==t[j-1])  ans+= f(i-1,j-1,s,t,len+1,dp);
        ans+= f(i-1,j,s,t,len,dp);
        return dp[i][j]=ans;
    }

public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,0,dp);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;<=n;i++)    dp[i][0]=0;
        // for(int j=0;j<=m;j++)   dp[0][j]=0;
        // for(int i=0)

    }
};








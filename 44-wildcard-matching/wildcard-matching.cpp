class Solution {
    bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        
        if(i==0 && j==0)   return true;
        if(i>0 && j==0)  return false;
        if(i==0 &&j>0){
            for(int ind=1;ind<=j;ind++){
                if(p[ind-1]!='*')     return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(p[j-1]==s[i-1] || p[j-1]=='?')  {
            return dp[i][j]= f(i-1,j-1,s,p,dp);
        }
        else if(p[j-1]=='*'){
            return dp[i][j]= f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,s,p,dp);

        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        // dp[0][0]=true;
        // for(int i=1;i<=n;i++)   dp[i][0]=false;
        // for(int j=1;j<=m;j++){
        //     if(p[j-1]=='*') dp[0][j]=true;
        //     else break;
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(p[j-1]==s[i-1] || p[j-1]=='?')  {
        //             dp[i][j]= dp[i-1][j-1];
        //         }
        //         else if(p[j-1]=='*'){
        //             dp[i][j]= dp[i-1][j] || dp[i][j-1];
        //         }
        //         else dp[i][j]=false;
        //     }
        // }
        // return dp[n][m];

        vector<bool>pre(m+1,false),cur(m+1,false);
        pre[0]=true;
        for(int j=1;j<=m;j++){
            if(p[j-1]=='*') pre[j]=true;
            else break;
        }
        for(int i=1;i<=n;i++){
            cur[0]=false;
            for(int j=1;j<=m;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='?')  {
                    cur[j]= pre[j-1];
                }
                else if(p[j-1]=='*'){
                    cur[j]= pre[j] || cur[j-1];
                }
                else cur[j]=false;
            }
            pre=cur;
        }
        return pre[m];
    }
};
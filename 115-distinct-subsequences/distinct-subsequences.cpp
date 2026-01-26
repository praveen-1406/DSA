class Solution {
    // int f(int i,int j,string &s,string &t,int len,vector<vector<int>>&dp){
        
    //     if(j==0)    return 1;
    //     if(i==0)    return 0;
        
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     int ans=0;
    //     if(s[i-1]==t[j-1])  ans+= f(i-1,j-1,s,t,len+1,dp);
    //     ans+= f(i-1,j,s,t,len,dp);
    //     return dp[i][j]=ans;
    // }

public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,s,t,0,dp);

        // vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        vector<unsigned long long>pre(m+1,0),cur(m+1,0);
        for(int j=0;j<=m;j++)   pre[j]=0;         //where i is 0
        // for(int i=0;i<=n;i++)    dp[i][0]=1;         //where j is 0
        pre[0]=1;
        for(int i=1;i<=n;i++){
            cur[0]=1;
            for(int j=1;j<=m;j++){
                cur[j]=pre[j];
                if(s[i-1]==t[j-1])  cur[j]+=pre[j-1];
            }
            pre=cur;
        }
        return (int)pre[m];
    }
};








class Solution {
    // int f(int i1,int i2,string &s1,string &s2,vector<vector<int>>&dp){
    //     if(i1==0 || i2==0)   return 0;
    //     if(dp[i1][i2]!=-1)  return dp[i1][i2];
    //     if(s1[i1-1]==s2[i2-1])  return dp[i1][i2]= 1+f(i1-1,i2-1,s1,s2,dp);
    //     return dp[i1][i2]= 0+max(f(i1-1,i2,s1,s2,dp),f(i1,i2-1,s1,s2,dp));
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,text1,text2,dp);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>pre(m+1,0),cur(m+1,0);
        // for(int i=0;i<=n;i++)   dp[i][0]=0;
        for(int j=0;j<=m;j++)   pre[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])      cur[j]=1+pre[j-1];
                else    cur[j]=max(pre[j],cur[j-1]);
            }
            pre=cur;
        }
        return pre[m];
    }
};
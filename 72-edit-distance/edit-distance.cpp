class Solution {
    // int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    //     if(i<0 && j<0)  return 0;
    //     if(i<0)     return j+1;
    //     if(j<0)     return i+1;

    //     if(dp[i][j]!=-1)    return dp[i][j];

    //     if(s1[i]==s2[j])    return dp[i][j]=f(i-1,j-1,s1,s2,dp);
        
    //     int a=f(i,j-1,s1,s2,dp);   //insert in s1
    //     int b=f(i-1,j,s1,s2,dp);   //delete in s1
    //     int c=f(i-1,j-1,s1,s2,dp); //replace in s1
    //     return dp[i][j]= 1+min(min(a,b),c);
        
    // }
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        // return f(n-1,m-1,s1,s2);
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,s1,s2,dp);

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=0;
        for(int j=0;j<=m;j++)   dp[0][j]=j;
        for(int i=0;i<=n;i++)   dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
                }
            }
        }

        return dp[n][m];


    }
};
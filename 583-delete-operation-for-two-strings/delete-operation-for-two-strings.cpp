class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>pre(m+1,0),cur(m+1,0);
        // for(int i=0;i<=n;i++)   dp[i][0]=0;
        for(int j=0;j<=m;j++)   pre[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1])    cur[j]=1+pre[j-1];
                else    cur[j]=max(pre[j],cur[j-1]);
            }
            pre=cur;
        }

        return (n-pre[m])+(m-pre[m]);
    }
};
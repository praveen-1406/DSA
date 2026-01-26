class Solution {
    
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)   dp[i][0]=0;
        for(int j=0;j<=m;j++)   dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])    dp[i][j]=1+dp[i-1][j-1];
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int len=dp[n][m];
        string lcs(len,'$');
        int i=n,j=m,ind=len-1;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                lcs[ind--]=s1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j]>=dp[i][j]){
                i--;
            }else{
                j--;
            }
        } 

        int l=n+m-len;
        string ans(l,'$');
        int a=0,b=0,c=0,idx=0;
        while(idx<len){
            if(a<n && s1[a]!=lcs[idx]){
                ans[c]=s1[a];
                a++;
                c++;
            }else if(b<m && s2[b]!=lcs[idx]){
                ans[c]=s2[b];
                b++;
                c++;
            }else{
                ans[c]=lcs[idx];
                idx++;
                c++;
                a++;
                b++;
            }
        }
        while(a<n){
            ans[c]=s1[a];
            a++;
            c++;
        }
        while(b<m){
            ans[c]=s2[b];
            b++;
            c++;
        }
        return ans;

    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(n==0)    return m;
        if(m==0)    return n;
        vector<long long>cur(m+1,0),pre(m+1,0);
        for(int i=0;i<m+1;i++){
            pre[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cur[0]=i;
                if(word1[i-1]==word2[j-1]){
                    cur[j]=pre[j-1];
                }
                else{
                    cur[j]=1+min(pre[j-1],min(cur[j-1],pre[j]));    //(r,i,d)
                }
            }
            pre=cur;
        }
        return pre[m];
    }
};
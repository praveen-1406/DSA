class Solution {

    // int f(int i,string s){
    //     if()
    // }

public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>preb(n);
        vector<int>posta(n);
        preb[0]=0;
        posta[n-1]=0;
        for(int i=1;i<n;i++){
            preb[i]=(s[i-1]=='b')?preb[i-1]+1:preb[i-1];
            posta[n-1-i]=(s[n-i]=='a')?posta[n-i]+1:posta[n-i];
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,preb[i]+posta[i]);
        }
        return ans;
    }
};
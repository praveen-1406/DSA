class Solution {
    bool check(string w1,string w2){
        //w1 is predecessor or w2
        int n=w1.size(),m=w2.size();
        if(n+1!=m)  return false;
        int i=0,j=0,cnt=0;
        while(j<m){
            if(w1[i]==w2[j]){
                j++;
                i++;
            }
            else    j++;
        }
        if(j==m && i==n)    return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string w1,string w2){
            return w1.size()<w2.size();
        });
        vector<int>dp(n,1);
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int pre=0;pre<ind;pre++){
                if(check(words[pre],words[ind]) && dp[pre]+1>dp[ind]){
                    dp[ind]=dp[pre]+1;
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};
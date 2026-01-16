class Solution {
    int f(int ind,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            return (amt%coins[0]==0);
        }
        if(dp[ind][amt]!=-1)    return dp[ind][amt];
        int pick=0;
        if(amt>=coins[ind])     pick=f(ind,amt-coins[ind],coins,dp);
        int notPick=f(ind-1,amt,coins,dp);

        return dp[ind][amt]= pick+notPick;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return f(n-1,amount,coins,dp);

        // vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
        vector<unsigned long long>pre(amount+1,0),cur(amount+1,0);

        for(int i=0;i<=amount;i++)    if(i%coins[0]==0)     pre[i]=1;
        for(int ind=1;ind<n;ind++){
            for(int amt=0;amt<=amount;amt++){
                unsigned long long pick=0;
                if(amt>=coins[ind])     pick=cur[amt-coins[ind]];
                unsigned long long notPick=pre[amt];

                cur[amt]=pick+notPick;
            }   
            pre=cur;
        }
        return (int)pre[amount];

    }
};
class Solution {
// Memoization
    // int f(int amt,vector<int>& coins,vector<int>&dp){
    //     if(amt==0)  return 0;
    //     if(dp[amt]!=-1)     return dp[amt];
    //     int mincnt=20000;
    //     for(int i=0;i<coins.size();i++){
    //         if(amt>=coins[i])    mincnt=min(mincnt,1+f(amt-coins[i],coins,dp));
    //     }
    //     return dp[amt]=mincnt;
    // }

    int f(int ind,int tar,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(tar%coins[0]==0)     return tar/coins[0];
            else return 1e9;
        }
        if(dp[ind][tar]!=-1)    return dp[ind][tar];
        int notPick=0+f(ind-1,tar,coins,dp);
        int pick=INT_MAX;
        if(tar>=coins[ind])     pick=1+f(ind,tar-coins[ind],coins,dp);
        return dp[ind][tar]=min(notPick,pick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        // vector<int>dp(amount+1,-1);
        // int ans=f(amount,coins,dp);
        // if(ans>=20000)    return -1;
        // return ans;


        // vector<vector<int>>dp(amount+1,vector<int>(amount+1,0));    // cnt,amt
        // for(int i=0;i<=amount;i++)  dp[i][0]=i;

        // for(int cnt=amount;cnt>=0;cnt--){
        //     for(int amt=1;amt<=amount;amt++){
        //         int mincnt=INT_MAX;
        //         for(int i=0;i<coins.size();i++){
        //             if(amt>=coins[i])    mincnt=min(mincnt,dp[cnt+1][amt-coins[i]]);
        //         }
        //         dp[cnt][amt]=mincnt;
        //     }
        // }
        // return dp[0][amount];

// Space Optimization
        // vector<int>dp(amount+1,0);

        // for(int amt=1;amt<=amount;amt++){
        //     int mincnt=20000;
        //     for(int i=0;i<coins.size();i++){
        //         if(amt>=coins[i])    mincnt=min(mincnt,1+dp[amt-coins[i]]);
        //     }
        //     dp[amt]=mincnt;
        // }
        // if(dp[amount]>=20000)    return -1;
        // return dp[amount];

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9)    return -1;
        return ans;

    }
};















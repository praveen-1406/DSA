class Solution {
    // int f(int amt,vector<int>& coins,vector<int>&dp){
    //     if(amt==0)  return 0;
    //     if(dp[amt]!=-1)     return dp[amt];
    //     int mincnt=20000;
    //     for(int i=0;i<coins.size();i++){
    //         if(amt>=coins[i])    mincnt=min(mincnt,1+f(amt-coins[i],coins,dp));
    //     }
    //     return dp[amt]=mincnt;
    // }

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

        vector<int>dp(amount+1,0);
        for(int amt=1;amt<=amount;amt++){
            int mincnt=20000;
            for(int i=0;i<coins.size();i++){
                if(amt>=coins[i])    mincnt=min(mincnt,1+dp[amt-coins[i]]);
            }
            dp[amt]=mincnt;
        }
        if(dp[amount]>=20000)    return -1;
        return dp[amount];

    }
};
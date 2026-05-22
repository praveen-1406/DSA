class Solution {
    int f(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0)   return 0;
        if(dp[amount]!=-1)  return dp[amount];
        int mini=INT_MAX;
        for(auto coin:coins){
            if(coin<=amount)    mini=min(mini,f(coins,amount-coin,dp));
        }
        if(mini==INT_MAX || mini==-1)  return dp[amount]= -1;
        return dp[amount]= 1+mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<int>dp(amount+1,-1);
        // return f(coins,amount,dp);

        vector<int>dp(amount+1,0);
        for(int amt=1;amt<=amount;amt++){
            int mini=INT_MAX;
            for(auto coin:coins){
                if(coin<=amt)    mini=min(mini,dp[amt-coin]);
            }
            if(mini==INT_MAX)    dp[amt]=INT_MAX;
            else    dp[amt]=1+mini;
        }
        if(dp[amount]==INT_MAX)     return -1;
        return dp[amount];
    }
};
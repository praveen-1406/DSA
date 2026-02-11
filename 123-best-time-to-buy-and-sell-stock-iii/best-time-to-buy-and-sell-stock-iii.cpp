class Solution {
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(buy>4)     return 0;
        if(ind==prices.size())      return 0;
        if(dp[ind][buy]!=-1)    return dp[ind][buy];
        int profit=0;
        if(buy%2)     profit=max(-prices[ind]+f(ind+1,buy+1,prices,dp),0+f(ind+1,buy,prices,dp));
        else        profit=max(prices[ind]+f(ind+1,buy+1,prices,dp),0+f(ind+1,buy,prices,dp));
        return dp[ind][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4+1,-1));
        return f(0,1,prices,dp);
    }
};
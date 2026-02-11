class Solution {
    // int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
    //     if(buy>4)     return 0;
    //     if(ind==prices.size())      return 0;
    //     if(dp[ind][buy]!=-1)    return dp[ind][buy];
    //     int profit=0;
    //     if(buy%2)     profit=max(-prices[ind]+f(ind+1,buy+1,prices,dp),0+f(ind+1,buy,prices,dp));
    //     else        profit=max(prices[ind]+f(ind+1,buy+1,prices,dp),0+f(ind+1,buy,prices,dp));
    //     return dp[ind][buy]= profit;
    // }
    int f(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(cap==0)     return 0;
        if(ind==prices.size())      return 0;
        if(dp[ind][buy][cap]!=-1)    return dp[ind][buy][cap];
        int profit=0;
        if(buy==1)     profit=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        else        profit=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));
        return dp[ind][buy][cap]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(4+1,-1));
        // return f(0,1,prices,dp);
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0,1,2,prices,dp);

        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // for(int ind=0;ind<=n;ind++){
        //     for(int buy=0;buy<2;buy++){
        //         for(int cap=0;cap<3;cap++){
        //             if(cap==0)  dp[ind][buy][cap]=0;
        //             if(ind==n)  dp[ind][buy][cap]=0;
        //         }
        //     }
        // }
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         for(int cap=1;cap<3;cap++){
        //             int profit=0;
        //             if(buy==1)     profit=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
        //             else        profit=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
        //             dp[ind][buy][cap]= profit;
        //         }
        //     }
        // }
        // return dp[0][1][2];

        vector<vector<int>>after(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<3;cap++){
                    int profit=0;
                    if(buy==1)     profit=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                    else        profit=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                    cur[buy][cap]= profit;
                }
            }
                after=cur;
        }
        return after[1][2];


    }
};
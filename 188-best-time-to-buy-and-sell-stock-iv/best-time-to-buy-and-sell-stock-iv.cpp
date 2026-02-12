class Solution {
    // int f(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
    //     if(cap==0)  return 0;
    //     if(ind==prices.size())  return 0;
    //     if(dp[ind][buy][cap]!=-1)   return dp[ind][buy][cap];
    //     int profit;
    //     if(buy){
    //         profit=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));
    //     }
    //     return dp[ind][buy][cap]=profit;
    // }

    int f(int ind,int tran,int k,vector<int>& prices,vector<vector<int>>&dp){
        if(ind==prices.size() || tran==2*k)  return 0;
        if(dp[ind][tran]!=-1)   return dp[ind][tran];
        int profit;
        if(tran%2==0){  //buy
            profit=max(-prices[ind]+f(ind+1,tran+1,k,prices,dp),0+f(ind+1,tran,k,prices,dp));
        }
        else{   //sell
            profit=max(prices[ind]+f(ind+1,tran+1,k,prices,dp),0+f(ind+1,tran,k,prices,dp));
        }
        return dp[ind][tran]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return f(0,1,k,prices,dp);

        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         for(int cap=1;cap<=k;cap++){
        //             int profit;
        //             if(buy){
        //                 profit=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
        //             }
        //             else{
        //                 profit=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
        //             }
        //             dp[ind][buy][cap]=profit;
        //         }
        //     }
        // }
        // return dp[0][1][k];

        // vector<vector<int>>after(2,vector<int>(k+1,0)),cur(2,vector<int>(k+1,0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         for(int cap=1;cap<=k;cap++){
        //             int profit;
        //             if(buy){
        //                 profit=max(-prices[ind]+after[0][cap],0+after[1][cap]);
        //             }
        //             else{
        //                 profit=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
        //             }
        //             cur[buy][cap]=profit;
        //         }
        //         after=cur;
        //     }
        // }
        // return after[1][k];

        // vector<vector<int>>dp(n,vector<int>(2*k,-1));
        // return f(0,0,k,prices,dp);

        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int tran=2*k-1;tran>=0;tran--){
                int profit;
                if(tran%2==0){  //buy
                    profit=max(-prices[ind]+dp[ind+1][tran+1],0+dp[ind+1][tran]);
                }
                else{   //sell
                    profit=max(prices[ind]+dp[ind+1][tran+1],0+dp[ind+1][tran]);
                }
                dp[ind][tran]=profit;
            }
        }
        return dp[0][0];

    }
};
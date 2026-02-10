class Solution {
    int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size())  return 0;
        if(dp[ind][buy]!=-1)    return dp[ind][buy];
        int profit;
        if(buy)     profit=max(-prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp));
        else    profit=max(prices[ind]+f(ind+1,1,prices,dp),0+f(ind+1,0,prices,dp));
        return dp[ind][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,prices,dp);

        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // vector<int>ahead(2,0),cur(2,0);
        // ahead[0]=ahead[1]=0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<2;buy++){
        //         int profit;
        //         if(buy)     profit=max(-prices[ind]+ahead[0],0+ahead[1]);
        //         else    profit=max(prices[ind]+ahead[1],0+ahead[0]);
        //         cur[buy]=profit;
        //     }
        //     ahead=cur;
        // }
        // return ahead[1];

        
        int aheadNotBuy,aheadBuy,curNotBuy,curBuy;
        aheadNotBuy=aheadBuy=0;
        for(int ind=n-1;ind>=0;ind--){
            curBuy=max(-prices[ind]+aheadNotBuy,0+aheadBuy);
            curNotBuy=max(prices[ind]+aheadBuy,0+aheadNotBuy);
                
            aheadBuy=curBuy;
            aheadNotBuy=curNotBuy;
            
        }
        return aheadBuy;


    }
};
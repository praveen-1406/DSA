class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int n=prices.size();
        if(n<=1)    return 0;
        int minprice=prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]<=minprice){
                minprice=prices[i];
            }else{
                maxProfit=max(maxProfit,prices[i]-minprice);
            }
        }
        return maxProfit;
    }
};
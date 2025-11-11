class Solution {
    // Memoization
    // int f(int ind,vector<int>&nums,vector<int>&dp){
    //     if(ind<0)   return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int m1=0,m2=0;
    //     m1=nums[ind]+f(ind-2,nums,dp);
    //     m2=f(ind-1,nums,dp);
    //     return dp[ind]=max(m1,m2);
    // }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        // return f(n-1,nums,dp);

        // Tabulation
        // if(n==1)    return nums[0];
        // dp[0]=nums[0],dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        // }
        // return dp[n-1];

        // Space optimization
        if(n==1)    return nums[0];
        int prev2=nums[0],prev=max(nums[0],nums[1]),curi;
        for(int i=2;i<n;i++){
            curi=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curi;
        }
        return prev;

    }   
};
class Solution {
    // int f(int ind,vector<int>&nums){
    //     if(ind<0)  return 0;
    //     int m1=0,m2=0;
    //     if(ind-2>=0)    m1=f(ind-2,nums);
    //     if(ind-3>=0)    m2=f(ind-3,nums);
    //     return max(nums[ind]+m1,nums[ind]+m2);
    // }
    int f(int ind,vector<int>&nums,vector<int>&dp){
        if(ind<0)   return 0;
        if(dp[ind]!=-1) return dp[ind];
        int m1=0,m2=0;
        m1=nums[ind]+f(ind-2,nums,dp);
        m2=f(ind-1,nums,dp);
        return dp[ind]=max(m1,m2);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }   
};
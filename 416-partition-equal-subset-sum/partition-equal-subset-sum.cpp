class Solution {
    // Recursion
    bool f(int ind,int a,int b,vector<int>&nums,vector<vector<int>>&dp){
        if(ind<0 && a==b)   return true;
        if(ind<0 && a!=b)   return false;
        if(dp[ind][a]!=-1)   return dp[ind][a];
        bool picka=f(ind-1,a+nums[ind],b,nums,dp);
        bool pickb=f(ind-1,a,b+nums[ind],nums,dp);
        return dp[ind][a]=(picka || pickb);
    }

    // Memoization
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        // Recursion
        // return f(n-1,0,0,nums);

        // Memoization
        vector<vector<int>>dp(n,vector<int>(n*100,-1));
        return f(n-1,0,0,nums,dp);
    }
};
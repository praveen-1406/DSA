class Solution {

    // // Recursion
    // bool f(int ind,int k,vector<int>&nums){
    //     if(k==0)    return true;
    //     if(ind==0)    return (nums[0]==k);
    //     bool notPick=f(ind-1,k,nums);
    //     bool pick=false;
    //     if(k>=nums[ind])    pick=f(ind-1,k-nums[ind],nums);
    //     return (pick || notPick);
    // }
    
    // Memoization
    bool f(int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(k==0)    return true;
        if(ind==0)    return (nums[0]==k);
        if(dp[ind][k]!=-1)  return dp[ind][k];
        bool notPick=f(ind-1,k,nums,dp);
        bool pick=false;
        if(k>=nums[ind])    pick=f(ind-1,k-nums[ind],nums,dp);
        return dp[ind][k]=(pick || notPick);
    }


public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)    sum+=nums[i];
        if(sum%2==1)    return false;
        int k=sum/2;

        // Recursion
        // return f(n-1,k,nums);

        // Memoization
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);

        
    }
};
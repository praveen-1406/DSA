class Solution {
    // int f(int idx,int preIdx,vector<int>&nums){
    //     if(idx>=nums.size())    return 0;
    //     int ans=0;
    //     // not take
    //     ans=max(ans,0+f(idx+1,preIdx,nums));
    //     // take
    //     if(preIdx==-1 || nums[idx]>nums[preIdx])    ans=max(ans,1+f(idx+1,idx,nums));
    //     return ans;
    // }

    int f(int idx,int preIdx,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>=nums.size())    return 0;
        if(dp[idx][preIdx+1]!=-1)   return dp[idx][preIdx+1];
        int ans=0;
        // not take
        ans=max(ans,0+f(idx+1,preIdx,nums,dp));
        // take
        if(preIdx==-1 || nums[idx]>nums[preIdx])    ans=max(ans,1+f(idx+1,idx,nums,dp));
        return dp[idx][preIdx+1] = ans;
    }

    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // return f(0,-1,nums);
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,dp);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=0;i<=n;i++)   dp[n][i]=0;

        // for(int idx=n-1;idx>=0;idx--){
        //     for(int preIdx=n-1;preIdx>=-1;preIdx--){
        //         int ans=0;
        //         // not take
        //         ans=max(ans,0+dp[idx+1][preIdx+1]);
        //         // take
        //         if(preIdx==-1 || nums[idx]>nums[preIdx])    ans=max(ans,1+dp[idx+1][idx+1]);
        //         dp[idx][preIdx+1] = ans;
        //     }
        // }
        // return dp[0][0];

        vector<int>next(n+1,0),cur(n+1,0);
        // for(int i=0;i<=n;i++)   dp[n][i]=0;

        for(int idx=n-1;idx>=0;idx--){
            for(int preIdx=n-1;preIdx>=-1;preIdx--){
                int ans=0;
                // not take
                ans=max(ans,0+next[preIdx+1]);
                // take
                if(preIdx==-1 || nums[idx]>nums[preIdx])    ans=max(ans,1+next[idx+1]);
                cur[preIdx+1] = ans;
            }
            next=cur;
        }
        return next[0];
    }
};
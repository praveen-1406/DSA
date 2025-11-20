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
    // bool f(int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
    //     if(k==0)    return true;
    //     if(ind==0)    return (nums[0]==k);
    //     if(dp[ind][k]!=-1)  return dp[ind][k];
    //     bool notPick=f(ind-1,k,nums,dp);
    //     bool pick=false;
    //     if(k>=nums[ind])    pick=f(ind-1,k-nums[ind],nums,dp);
    //     return dp[ind][k]=(pick || notPick);
    // }


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
        // vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // return f(n-1,k,nums,dp);

        // Tabulation
        // vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        // for(int i=0;i<n;i++)    dp[i][0]=true;
        // if(nums[0]==k)    dp[0][nums[0]]=true;
        // for(int ind=1;ind<n;ind++){
        //     for(int tar=1;tar<=k;tar++){
        //         bool notPick=dp[ind-1][tar];
        //         bool pick=false;
        //         if(tar>=nums[ind])  pick=dp[ind-1][tar-nums[ind]];
        //         dp[ind][tar]=(pick || notPick);
        //     }
        // }
        // return dp[n-1][k];
    
        // Space Optimization
        vector<bool>pre(k+1,false),cur(k+1,false);
        pre[0]=true;
        // if(nums[0]==k)    pre[nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            cur[0]=true;
            for(int tar=1;tar<=k;tar++){
                bool notPick=pre[tar];
                bool pick=false;
                if(tar>=nums[ind])  pick=pre[tar-nums[ind]];
                cur[tar]=(pick || notPick);
            }
            pre=cur;
        }
        return pre[k];

        
    }
};
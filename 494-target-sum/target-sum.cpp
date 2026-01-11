class Solution {

    // int f(int ind,int tar,vector<int>&nums){
    //     if(ind == 0){
    //         int cnt=0;
    //         if(tar+nums[0]==0)  cnt++;
    //         if(tar-nums[0]==0)  cnt++;
    //         return cnt;
    //     }

    //     int plus=f(ind-1,tar+nums[ind],nums);
    //     int minus=f(ind-1,tar-nums[ind],nums);
    //     return plus+minus;

    // }

    // int f(int ind,int k,vector<int>&nums,vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(k==0 && nums[0]==0) return 2;
    //         if(k==0) return 1;
    //         return (k==nums[0]);
    //         return 0;
    //     }
    //     if(dp[ind][k]!=-1)  return dp[ind][k];
    //     int pick=0;
    //     if(k>=nums[ind])    pick=f(ind-1,k-nums[ind],nums,dp);
    //     int notPick=f(ind-1,k,nums,dp);
    //     return dp[ind][k]=(pick+notPick);
    // }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // return f(n-1,target,nums);

        // Count the subsets with sum k
        int sum=0;
        for(int i=0;i<n;i++)    sum+=nums[i];
        
        if((target>sum)||(sum-target)%2)    return 0;
        int k=(sum-target)/2;

        // vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // return f(n-1,k,nums,dp);

        vector<vector<int>>dp(n,vector<int>(k+1,0));
        dp[0][0]=1;
        if(nums[0]==0)  dp[0][0]=2;
        if(nums[0]!=0 && k>=nums[0])  dp[0][nums[0]]=1;

        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=k;tar++){
                int pick=0;
                if(tar>=nums[ind])    pick=dp[ind-1][tar-nums[ind]];
                int notPick=dp[ind-1][tar];
                dp[ind][tar]=(pick+notPick);
            }
        }
        return dp[n-1][k];
    }
};











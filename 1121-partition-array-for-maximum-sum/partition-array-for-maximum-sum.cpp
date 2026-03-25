class Solution {
    int f(int ind,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(ind==n)     return 0;
        if(dp[ind]!=-1)    return dp[ind];
        int len=0;
        int maxi=INT_MIN;
        int ans=INT_MIN;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            ans=max(ans,len*maxi+f(j+1,k,arr,dp));
        }
        return dp[ind] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // Front Partition
        vector<int>dp(n,-1);
        return f(0,k,arr,dp);
    }
};
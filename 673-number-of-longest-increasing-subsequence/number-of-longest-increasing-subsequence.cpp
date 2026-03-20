class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>dp(n,{1,1});  // subsequence length, number of subsequence
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int pre=0;pre<ind;pre++){
                if(nums[pre]<nums[ind]){
                    if(dp[pre].first+1>dp[ind].first){
                        dp[ind].first=dp[pre].first+1;
                        dp[ind].second=dp[pre].second;
                    }else if(dp[pre].first+1==dp[ind].first){
                        dp[ind].second+=dp[pre].second;
                    }
                }
            }
            if(dp[ind].first>maxi){
                maxi=dp[ind].first;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i].first) cnt+=dp[i].second;
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int lastInd=0;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int pre=0;pre<ind;pre++){
                if((nums[ind]%nums[pre]==0) && 1+dp[pre]>dp[ind]){
                    dp[ind]=1+dp[pre];
                    hash[ind]=pre;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastInd=ind;
            }
        }
        vector<int>ans;
        while(hash[lastInd]!=lastInd){
            ans.push_back(nums[lastInd]);
            lastInd=hash[lastInd];
        }
        ans.push_back(nums[lastInd]);
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};
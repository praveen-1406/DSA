class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int s=INT_MAX;
        int ans=-1;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j]>nums[i])     maxi=max(maxi,nums[j]-nums[i]);
        //     }
        // }
        for(int i=0;i<n;i++){
            s=min(nums[i],s);
            if(nums[i]>s){
                ans=max(ans,nums[i]-s);
            }
        }
        return ans;

    }
};
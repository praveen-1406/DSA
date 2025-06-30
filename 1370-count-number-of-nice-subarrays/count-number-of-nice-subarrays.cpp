class Solution {
public:
    int func(vector<int>&nums,int k){
        int r=0,l=0,cntOdd=0,cnt,n=nums.size();
        while(r<n){
            if(nums[r]%2==1)    cntOdd++;
            while(cntOdd>k){
                if(nums[l]%2==1)    cntOdd--;
                l++;
            }
            if(cntOdd<=k)   cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=func(nums,k)-func(nums,k-1);
        return ans;
    }
};
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

    int f(int ind,int k,vector<int>&nums){
        if(ind==0){
            if(k==0){
                if(nums[0]==0)  return 2;
                else return 1;
            }
            else if(k==nums[0]) return 1;
            return 0;
        }
        int pick=0;
        if(k>=nums[ind])    pick=f(ind-1,k-nums[ind],nums);
        int notPick=f(ind-1,k,nums);
        return (pick+notPick);
    }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // return f(n-1,target,nums);

        // Count the subsets with sum k
        int sum=0;
        for(int i=0;i<n;i++)    sum+=nums[i];
        int k=0;
        if((sum-target)%2==0) k=(sum-target)/2;
        else return 0;

        return f(n-1,k,nums);
    }
};











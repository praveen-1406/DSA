class Solution {

    int f(int ind,int tar,vector<int>&nums){
        if(ind == 0){
            int cnt=0;
            if(tar+nums[0]==0)  cnt++;
            if(tar-nums[0]==0)  cnt++;
            return cnt;
        }

        int plus=f(ind-1,tar+nums[ind],nums);
        int minus=f(ind-1,tar-nums[ind],nums);
        return plus+minus;

    }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,target,nums);
    }
};
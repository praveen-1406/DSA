class Solution {
    int maxSum(vector<int>&nums){
        int n=nums.size();
        if(n==1)    return nums[0];
        int prev2=nums[0],prev=max(nums[0],nums[1]),curi;
        for(int i=2;i<n;i++){
            curi=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)    temp1.push_back(nums[i]);
            if(i!=n-1)  temp2.push_back(nums[i]);
        }
        return max(maxSum(temp1),maxSum(temp2));
    }
};
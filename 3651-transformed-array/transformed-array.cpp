class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result[i]=nums[(i+nums[i])%n];
            }else if(nums[i]<0){
                result[i]=((abs(nums[i])%n)<=i)?(nums[i-(abs(nums[i])%n)]): (nums[n+(i-(abs(nums[i])%n))]);
            }else   result[i]=nums[i];
        }
        return result;
    }
};
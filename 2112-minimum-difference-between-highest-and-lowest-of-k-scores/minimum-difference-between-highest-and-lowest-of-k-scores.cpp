class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1)    return 0;
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int a=0;
        int b=k-1;
        while(b<nums.size()){
            diff=min(diff,nums[b]-nums[a]);
            a++;
            b++;
        }
        return diff;
    }
};
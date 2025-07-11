class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)  return 0;
        int maxi=nums[0];
        int cnt=0;
        int end=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,i+nums[i]);
            if(i==end && i!=nums.size()-1){
                cnt++;
                end=maxi;
            }
        }
        return cnt;
    }
};
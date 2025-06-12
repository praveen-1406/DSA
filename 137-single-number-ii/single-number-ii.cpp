class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bitIdx=0;bitIdx<32;bitIdx++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] & (1<<bitIdx)) cnt++;
            }
            if(cnt%3==1)    ans=ans | 1<<bitIdx;
        }
        return ans;
    }
};
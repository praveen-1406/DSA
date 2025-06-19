class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=1,fidx=0;
        for(int i=0;i<nums.size();i++){
            if(!(nums[i]-nums[fidx]<=k)) {
                fidx=i;
                cnt++;
            }
        }
        return cnt;
    }
};
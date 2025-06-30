class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0,cnt=0;
        int n=nums.size();
        unordered_map<int,int>hash;
        hash[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(hash.find(sum-goal)!=hash.end()) {
                cnt+=hash[sum-goal];
            }
            hash[sum]++;
        }
        return cnt;
    }
};
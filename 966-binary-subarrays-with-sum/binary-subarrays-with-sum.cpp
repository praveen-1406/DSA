class Solution {
public:
    int func(vector<int>& nums, int goal){
        if(goal<0)  return 0;
        int l=0,r=0,sum=0,cnt=0;
        int n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;                
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int sum=0,cnt=0;
        // int n=nums.size();
        // unordered_map<int,int>hash;
        // hash[0]=1;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        //     if(hash.find(sum-goal)!=hash.end()) {
        //         cnt+=hash[sum-goal];
        //     }
        //     hash[sum]++;
        // }
        // return cnt;
        int ans=func(nums,goal)-func(nums,goal-1);
        return ans;
    }
};
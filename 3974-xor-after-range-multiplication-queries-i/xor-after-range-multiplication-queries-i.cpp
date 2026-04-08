class Solution {
    int MOD=1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];
            int idx=l;
            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%MOD;
                idx+=k;
            }
        }
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }

        return ans;
    }
};
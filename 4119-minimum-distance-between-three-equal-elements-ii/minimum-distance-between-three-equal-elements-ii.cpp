class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        vector<vector<int>>v(n+1);
        for(int i=0;i<n;i++){
            v[nums[i]].push_back(i);
        }
        for(auto i:v){
            if(i.size()>=3){
                int k=2;
                while(k<i.size()){
                    ans=min(ans,2*(i[k]-i[k-2]));
                    k++;
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};
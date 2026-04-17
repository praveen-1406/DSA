class Solution {
    int rev(int n){
        int r=0;
        while(n){
            r=r*10+n%10;
            n/=10;
        }
        return r;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        // unordered_map<int,vector<int>>mp;
        // vector<int>rnums;
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     mp[nums[i]].push_back(i);
        //     rnums.push_back(rev(nums[i]));
        // }
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     vector<int>&v=mp[rnums[i]];
        //     if(v.empty())   continue;
        //     int m=v.size();
        //     int l=0,r=m-1;
        //     while(l<=r){
        //         int mid=l+(r-l)/2;
        //         if(v[mid]>i){
        //             ans=min(ans,abs(v[mid]-i));
        //             r=mid-1;
        //         }else{
        //             l=mid+1;
        //         }
        //     }
        // }
        // if(ans==INT_MAX)    return -1;
        // return ans;

        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[rev(nums[i])]=i;
        }
        if(ans==INT_MAX)    return -1;
        return ans;
    }
};
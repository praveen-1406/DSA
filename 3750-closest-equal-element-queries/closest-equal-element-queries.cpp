class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(int q:queries){
            int val=nums[q];
            // int mini=INT_MAX;
            // for(int ind:mp[val]){
            //     if(ind!=q){
            //         mini=min(mini,min(abs(q-ind),n-abs(ind-q)));
            //     }
            // }
            //     if(mini==INT_MAX)   ans.push_back(-1);
            //     else    ans.push_back(mini);
            // Binary Search
            auto &v=mp[val];
            int m=v.size();
            if(m==1) ans.push_back(-1);
            else{
                int l=0,r=v.size()-1;
                int mid;
                while(l<=r){
                    mid=(l+r)/2;
                    if(v[mid]==q)  break;
                    else if(v[mid]<q)  l=mid+1;
                    else    r=mid-1;
                }
                int prev=(mid-1+m)%m;
                int next=(mid+1)%m;
                int v1=min(abs(q-v[prev]),n-abs(q-v[prev]));
                int v2=min(abs(q-v[next]),n-abs(q-v[next]));
                ans.push_back(min(v1,v2));
            }
            
        }   
        return ans;
    }
};
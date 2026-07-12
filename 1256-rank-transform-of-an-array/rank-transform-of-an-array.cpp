class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans(arr.size());
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int rnk=1;
        for(auto p:mp){
            for(int ind:p.second){
                ans[ind]=rnk;
            }
            rnk++;
        }
        return ans;
    }
};
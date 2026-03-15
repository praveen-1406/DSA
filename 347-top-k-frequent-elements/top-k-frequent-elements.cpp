class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;   //min-heap
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});        //freq,element
            if(pq.size()>k)     pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
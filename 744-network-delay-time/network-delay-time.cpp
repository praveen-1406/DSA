class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // {dist,node}
        set<pair<int,int>>st;  
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        st.insert({0,k});
        while(!st.empty()){
            auto x=*st.begin();
            st.erase(x);
            int dis=x.first;
            int node=x.second;
            for(auto it:adj[node]){
                if(dis+it.second < dist[it.first]){
                    dist[it.first]=dis+it.second;
                    st.insert({dist[it.first],it.first});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)  return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};



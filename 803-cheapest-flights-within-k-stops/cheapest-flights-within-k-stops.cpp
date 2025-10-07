class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // {stops,{node,dist}}
        vector<int>dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto x=q.front();
            int stops=x.first;
            int node=x.second.first;
            int cost=x.second.second;
            q.pop();
            if(stops>k)     continue;
            for(auto it:adj[node]){
                if(it.second+cost<dist[it.first] && stops<=k){
                    dist[it.first]=it.second+cost;
                    q.push({stops+1,{it.first,dist[it.first]}});
                }
            }
        }
        if(dist[dst]==INT_MAX)  return -1;
        return dist[dst];

    }
};
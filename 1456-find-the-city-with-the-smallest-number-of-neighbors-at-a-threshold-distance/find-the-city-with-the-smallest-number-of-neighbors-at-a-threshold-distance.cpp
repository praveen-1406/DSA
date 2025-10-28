class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create matrix --- directed
        // Floyd-Warsall Algorithm: find shortest distance for every pair of nodes
        // Checks threshold count and note the city with min no of neighbours in threshold

        // direacted graph matrix
        vector<vector<int>>cost(n,(vector<int>(n,INT_MAX)));
        for(int i=0;i<n;i++)    cost[i][i]=0;
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }

        // Floyd-Warshall Algorithm---
        // for(int k=0;k<n;k++){
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++){
        //             if(cost[i][k]!=INT_MAX && cost[k][j]!=INT_MAX){
        //                 cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
        //             }
        //         }
        //     }
        // }

        // Dijkstra's Algorithm
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int src=0;src<n;src++){
            dist[src][src]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,src});
            while(!pq.empty()){
                int dis=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(int i=0;i<n;i++){
                    if(cost[node][i]!=INT_MAX && (dis+cost[node][i]<dist[src][i])){
                        dist[src][i]=dis+cost[node][i];
                        pq.push({dist[src][i],i});
                    }
                }
            }
        }

        // Checking
        int city=0,mcities=100;
        for(int i=0;i<n;i++){
            int rcities=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold)  rcities++; 
            }
            if(rcities <= mcities){
                mcities=rcities;
                city=i;
            }
        }
        return city;
    }
};
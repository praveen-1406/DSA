class Solution {
    const long long M=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);        // {node,time}
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;  // {time,node}
        vector<long long>time(n,LLONG_MAX);
        vector<long long>ways(n,0);
        ways[0]=1;
        time[0]=0;
        q.push({0,0}); // time,node
        while(!q.empty()){
            long long t=q.top().first;
            int node=q.top().second;
            q.pop();
            // if(t>time[node])    continue;
            
            for(auto it:adj[node]){
                long long newTime=it.second+t;
                if(newTime<time[it.first]){
                    time[it.first]=it.second+t;
                    ways[it.first]=ways[node];
                    q.push({newTime,it.first});
                }
                else if(newTime== time[it.first]){
                    time[it.first]=newTime;
                    ways[it.first]=(ways[it.first]+ways[node])%M;
                }
            }
        }
        return ways[n-1]%M;
    }
};






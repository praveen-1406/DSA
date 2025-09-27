class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        vector<vector<int>>adj(V);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]) indegree[it]++;
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                if(--indegree[i]==0)    q.push(i);
            }
        }
        if(topo.size()==V)   return topo;
        return {};
    }
};
class Solution {
private:
    
public:
    bool canFinish(int V, vector<vector<int>>& pre) {
        vector<vector<int>>adj(V);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        int cnt=0;
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto i:adj[node]){
                if(--indegree[i]==0)    q.push(i);
            }
        }

        if(cnt==V)  return true;
        return false;
    }
};
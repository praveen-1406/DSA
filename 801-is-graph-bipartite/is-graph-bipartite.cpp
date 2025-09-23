class Solution {
    bool bfs(int node,vector<vector<int>>& graph,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            int color=vis[node];
            for(auto it:graph[node]){
                if(vis[it]==0){
                    vis[it]=(color==1)?2:1;
                    q.push(it);
                }else if(vis[it]==color)     return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(bfs(i,graph,vis)==false)   return false;
            }
        }

        return true;
    }
};
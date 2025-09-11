class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[node-1][i]==1 && !vis[i+1]) dfs(i+1,vis,adj);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int n=isConnected.size();
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                provinces++;
                dfs(i,vis,isConnected);
            }
        }

        return provinces;
    }
};
class Solution {
    void dfs(int node,vector<int>&vis,vector<vector<int>>& isConnected){
        int n=isConnected.size();
        vis[node]=1;
        
        for(int i=0;i<n;i++){
            
            if( isConnected[node-1][i] && !vis[i+1]){
                dfs(i+1,vis,isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n+1,0);
        int prov=0;
        for(int i=1;i<=n;i++){
                if(!vis[i]){
                    prov++;
                    dfs(i,vis,isConnected);
                }
        }
        return prov;
    }
};
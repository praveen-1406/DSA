class Solution {
private:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&ans,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it] && dfs(it,graph,vis,ans,pathvis)==true) return true;
            else if(pathvis[it])   return true;
        }
        pathvis[node]=0;
        ans.push_back(node);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        vector<int>vis(graph.size(),0);
        vector<int>pathvis(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]) dfs(i,graph,vis,ans,pathvis);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
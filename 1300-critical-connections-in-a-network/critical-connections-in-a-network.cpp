class Solution {
    void tarjanAlgo(int node,int parent,vector<int>&visited,vector<vector<int>>&adj,vector<int>&tin,vector<int>&lowadj,vector<vector<int>>&cconn){
        visited[node]=1;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(visited[it]){
                lowadj[node]=min(lowadj[node],lowadj[it]);
            }else{
                tin[it]=tin[node]+1;
                lowadj[it]=tin[it];
                tarjanAlgo(it,node,visited,adj,tin,lowadj,cconn);
                lowadj[node]=min(lowadj[node],lowadj[it]);
                if(lowadj[it]>tin[node]){
                   cconn.push_back({node,it});
                }
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        vector<int>visited(n,0);
        vector<vector<int>>cconn;
        vector<int>tin(n,0);
        vector<int>lowadj(n,0);
        tin[0]=1;
        lowadj[0]=1;
        tarjanAlgo(0,-1,visited,adj,tin,lowadj,cconn);
        return cconn;
    }
};
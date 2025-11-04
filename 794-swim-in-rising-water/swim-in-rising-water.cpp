class Solution {
    vector<vector<int>>dir={{-1,0},{+1,0},{0,-1},{0,+1}};
    bool possible(int l,int r,int t,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        int n=grid.size();
        if(l<0||r<0||l>=n||r>=n||visited[l][r]==true||grid[l][r]>t) return false;
        visited[l][r]=true;
        if(l==n-1 && r==n-1)    return true;
        for(auto it:dir){
            int nl=l+it[0];
            int nr=r+it[1];
            if(possible(nl,nr,t,visited,grid)){
                return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        // int n=grid.size();
        // int l=grid[0][0];
        // int r=n*n-1;
        // int result=0;
        // while(l<=r){
        //     int mid=l+(r-l)/2;
        //     vector<vector<bool>>visited(n,vector<bool>(n,false));
        //     if(possible(0,0,mid,visited,grid)){
        //         result=mid;
        //         r=mid-1;
        //     }else{
        //         l=mid+1;
        //     }
        // }
        // return result;

        // Dijkstra's Algo
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        pq.push({grid[0][0],0,0});
        visited[0][0]=1;
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int h=it[0],x=it[1],y=it[2];
            ans=max(ans,h);
            if(x==n-1 && y==n-1)    return ans;
            for(auto &d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny]){
                    visited[nx][ny]=1;
                    pq.push({grid[nx][ny],nx,ny});
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // using Dijkstra's Algo
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;   // {dist,{row,col}}
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        if(grid[0][0]==1)   return -1;
        pq.push({1,{0,0}});
        dist[0][0]=1;
        while(!pq.empty()){
            auto x=pq.top();
            int dis=x.first;
            int row=x.second.first;
            int col=x.second.second;
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && grid[nrow][ncol]==0){
                        // if(i!=0 && j!=0 && dis+2 < dist[nrow][ncol]){
                        //     dist[nrow][ncol]=dis+2;
                        //     pq.push({dist[nrow][ncol],{nrow,ncol}});
                        // }else if((i==0 || j==0) && dis+1 < dist[nrow][ncol]){
                        //     dist[nrow][ncol]=dis+1;
                        //     pq.push({dist[nrow][ncol],{nrow,ncol}});
                        // }
                        if(dis+1 < dist[nrow][ncol]){
                            dist[nrow][ncol]=dis+1;
                            pq.push({dist[nrow][ncol],{nrow,ncol}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX)     return -1;
        return dist[n-1][n-1];
    }
};
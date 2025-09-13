class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int maxtime=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                
            }
        }
        
        int drow[] ={-1,0,+1,0};
        int dcol[] ={0,-1,0,+1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxtime=max(maxtime,time);
            // if(row>0 && !vis[row-1][col] && grid[row-1][col]==1){
            //     q.push({{row-1,col},time+1});
            //     vis[row-1][col]=2;
            // }
            // if(row<n-1 && !vis[row+1][col] && grid[row+1][col]==1){
            //     q.push({{row+1,col},time+1});
            //     vis[row+1][col]=2;
            // }
            // if(col>0 && !vis[row][col-1] && grid[row][col-1]==1){
            //     q.push({{row,col-1},time+1});
            //     vis[row][col-1]=2;
            // }
            // if(col<m-1 && !vis[row][col+1] && grid[row][col+1]==1){
            //     q.push({{row,col+1},time+1});
            //     vis[row][col+1]=2;
            // }
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) {
                    if(vis[i][j]==0)    return -1;
                }
            }
        }
        
        return maxtime;
    }
};
class Solution {
public:

    void dfs(int row,int col,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,n,m,vis,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,n,m,vis,grid);
            }
            //last col
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,n,m,vis,grid);
            }
        }
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,n,m,vis,grid);
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,n,m,vis,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)   cnt++;
            }
        }
        return cnt;
    }
};




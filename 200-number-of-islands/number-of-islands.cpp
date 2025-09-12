class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            // traverse in the neighbours
            if(row>0 && grid[row-1][col]=='1'&&!vis[row-1][col]){
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(row<n-1 && grid[row+1][col]=='1'&&!vis[row+1][col]){
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if(col>0 && grid[row][col-1]=='1'&&!vis[row][col-1]){
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
            if(col<m-1 && grid[row][col+1]=='1'&&!vis[row][col+1]){
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};
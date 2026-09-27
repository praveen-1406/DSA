class Solution {
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[]={-1,0,+1,0};
            int dy[]={0,-1,0,+1};
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]=='1' && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                } 
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    islands++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return islands;
    }
};
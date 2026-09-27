class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==2){
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        if(q.empty()){
            for(int row=0;row<m;row++){
                for(int col=0;col<n;col++){
                    if(grid[row][col]==1){
                        return -1;
                    }
                }
            }
            return 0;
        }

        int time=0;
        while(!q.empty()){
            time++;
            int s=q.size();
            int dx[]={-1,0,+1,0};
            int dy[]={0,+1,0,-1};
            for(int z=1;z<=s;z++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int x=row+dx[k];
                    int y=col+dy[k];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1 && vis[x][y]==0){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1 && vis[row][col]==0){
                    return -1;
                }
            }
        }
        return time-1;
    }
};
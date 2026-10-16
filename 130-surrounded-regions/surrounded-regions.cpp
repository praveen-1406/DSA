class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int col=0;col<n;col++){
            if(!vis[0][col] && board[0][col]=='O'){
                q.push({0,col});
                vis[0][col]=1;
            }
        }
        for(int col=0;col<n;col++){
            if(!vis[m-1][col] && board[m-1][col]=='O'){
                q.push({m-1,col});
                vis[m-1][col]=1;
            }
        }
        for(int row=0;row<m;row++){
            if(!vis[row][0] && board[row][0]=='O'){
                q.push({row,0});
                vis[row][0]=1;
            }
        }
        for(int row=0;row<m;row++){
            if(!vis[row][n-1] && board[row][n-1]=='O'){
                q.push({row,n-1});
                vis[row][n-1]=1;
            }
        }
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && board[nx][ny]=='O'){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!vis[row][col] && board[row][col]=='O'){
                    board[row][col]='X';
                }
            }
        }
    }
};
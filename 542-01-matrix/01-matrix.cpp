class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0)); 
        vector<vector<int>>dist(m,vector<int>(n,1000)); 

        queue<pair<pair<int,int>,int>>q;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==0){
                    q.push({{row,col},0});
                    vis[row][col]=1;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            dist[r][c]=d;
            q.pop();
            int dx[]={-1,0,+1,0};
            int dy[]={0,-1,0,+1};
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx>=0 && ny>=0 && nx<mat.size() && ny<mat[0].size() && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({{nx,ny},d+1});
                    
                }
            }
        }

        return dist;
    }
};
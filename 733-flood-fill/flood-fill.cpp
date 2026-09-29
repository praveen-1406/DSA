class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pc=image[sr][sc];
        vector<vector<int>>ans=image;
        int m=image.size(),n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        ans[sr][sc]=color;
        vis[sr][sc]=1;
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=x+dx[i];
                int col=y+dy[i];
                if(row>=0 && col>=0 && row<m && col<n && !vis[row][col] && image[row][col]==pc){
                    vis[row][col]=1;
                    q.push({row,col});
                    ans[row][col]=color;
                }
            }
        }
        return ans;
    }
};
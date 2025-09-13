class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>&ans,int drow[],int dcol[],int init,int color){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==init){
                dfs(nrow,ncol,image,ans,drow,dcol,init,color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int init=image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<int>>ans=image;
        q.push({sr,sc});
        if(init == color) return image;
        // ans[sr][sc]=color;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};

        // while(!q.empty()){
        //     int row=q.front().first;
        //     int col=q.front().second;
        //     q.pop();
        //     for(int i=0;i<4;i++){
        //         int nrow=row+drow[i];
        //         int ncol=col+dcol[i];
        //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==init){
        //                 ans[nrow][ncol]=color;
        //                 q.push({nrow,ncol});
        //         }
        //     }
        // }
        dfs(sr,sc,image,ans,drow,dcol,init,color);
        return ans;
    }
};
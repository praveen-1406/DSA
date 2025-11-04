class Solution {
    vector<vector<int>>dir={{-1,0},{+1,0},{0,-1},{0,+1}};
    bool possible(int l,int r,int t,vector<vector<bool>>&visited,vector<vector<int>>& grid){
        int n=grid.size();
        if(l<0||r<0||l>=n||r>=n||visited[l][r]==true||grid[l][r]>t) return false;
        visited[l][r]=true;
        if(l==n-1 && r==n-1)    return true;
        for(auto it:dir){
            int nl=l+it[0];
            int nr=r+it[1];
            if(possible(nl,nr,t,visited,grid)){
                return true;
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        int l=grid[0][0];
        int r=n*n-1;
        int result=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            if(possible(0,0,mid,visited,grid)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};
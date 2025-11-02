class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);  // for 1 base indexing
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)    parent[i]=i;
    }

    int findParent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u,int v){
        // ultimate parents
        int upu=findParent(u);
        int upv=findParent(v);

        if(upu==upv)    return;

        if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }
        else {
            parent[upv]=upu;  // or parent[upu]=upv;
            rank[upu]++;
        }
    }

    void unionBySize(int u,int v){
        // ultimate parents
        int upu=findParent(u);
        int upv=findParent(v);

        if(upu==upv)    return;

        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else {   // size[upu]>size[upv] or size[upu]==size[upv]
            parent[upv]=upu;  // or parent[upu]=upv;
            size[upu]+=size[upv];
        }
    }

};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        //adj island parent in set then add the sizes of comp +1
        int n=grid.size();
        DisjointSet ds(n*n-1);
        int dr[]={-1,0,+1,0};
        int dc[]={0,-1,0,+1};
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){      
                    for(int idx=0;idx<4;idx++){
                        int nrow=row+dr[idx];
                        int ncol=col+dc[idx];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                            ds.unionBySize(nrow*n+ncol,row*n+col);
                        }
                    }             
                }
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                unordered_set<int>comp;
                if(grid[row][col]==0){
                    for(int idx=0;idx<4;idx++){
                        int nrow=row+dr[idx];
                        int ncol=col+dc[idx];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==1){
                            comp.insert(ds.findParent(nrow*n+ncol));
                        }
                    }
                    int size=1;
                    for(auto it:comp){
                        size+=ds.size[it];
                    }
                    ans=max(ans,size);
                }else{
                    ans=max(ans,ds.size[ds.findParent(row*n+col)]);
                }
            }
        }
        return ans;
    }
};















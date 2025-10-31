// class DisjointSet{
// public:
//     map<pair<int,int>,pair<int,int>>parent;
//     map<pair<int,int>,int>size;
    
//     pair<int,int> findParent(pair<int,int>p){
//         if(parent[p]==p)    return p;
//         return parent[p]=findParent(parent[p]);
//     }
//     void unionBySize(pair<int,int>u,pair<int,int>v){
//         pair<int,int>upu=findParent(u);
//         pair<int,int>upv=findParent(v);
//         if(upu==upv)    return;
//         if(size[upu]<size[upv]){
//             parent[upu]=upv;
//             size[upv]+=size[upu];
//         }
//         else{
//             parent[upv]=upu;
//             size[upu]+=size[upv];
//         }
//     }
    
// };
class DisjointSet{
public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)    parent[i]=i;
    }
    int findParent(int p){
        if(parent[p]==p)    return p;
        return parent[p]=findParent(parent[p]);
    }
    void unionBySize(int u,int v){
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv)    return;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // DisjointSet ds;
        // int n=stones.size();
        // for(auto it:stones){
        //     int r=it[0],c=it[1];
        //     ds.parent[{r,c}]={r,c};
        //     ds.size[{r,c}]=1;
        // }
        // for(int i=0;i<n;i++){
        //     auto u=stones[i];
        //     for(int j=i;j<n;j++){
        //         auto v=stones[j];
        //         if(u[0]==v[0] || u[1]==v[1]){
        //             ds.unionBySize({u[0],u[1]},{v[0],v[1]});
        //         }
        //     }
        // }
        // int comp=0;
        // for(auto it:ds.parent){
        //     if(it.first==it.second)     comp++;
        // }
        // return n-comp;

        int n=stones.size();
        int maxRow=0,maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxRow+1;
            ds.unionBySize(row,col);
            stoneNodes[row]=1;
            stoneNodes[col]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findParent(it.first)==it.first)   cnt++;
        }
        return n-cnt;
    }

};















class DisjointSet{
    vector<int>size,parent;
public:
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)    parent[i]=i;
    }
    int findParent(int n){
        if(n==parent[n])    return n;
        return parent[n]=findParent(parent[n]);
    }
    void unionBySize(int u,int v){
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv)    return;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)   return -1;
        DisjointSet ds(n);
        for(auto it:connections){
            ds.unionBySize(it[0],it[1]);
        }
        int steps=0;
        for(int i=1;i<n;i++){
            if(ds.findParent(0)!=ds.findParent(i)){
                steps++;
                ds.unionBySize(0,i);
            }
        }
        return steps;
    }
};
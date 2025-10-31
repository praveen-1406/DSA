class DisjointSet{
public:
    map<pair<int,int>,pair<int,int>>parent;
    map<pair<int,int>,int>size;
    
    pair<int,int> findParent(pair<int,int>p){
        if(parent[p]==p)    return p;
        return parent[p]=findParent(parent[p]);
    }
    void unionBySize(pair<int,int>u,pair<int,int>v){
        pair<int,int>upu=findParent(u);
        pair<int,int>upv=findParent(v);
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
        DisjointSet ds;
        int n=stones.size();
        for(auto it:stones){
            int r=it[0],c=it[1];
            ds.parent[{r,c}]={r,c};
            ds.size[{r,c}]=1;
        }
        for(int i=0;i<n;i++){
            auto u=stones[i];
            for(int j=i;j<n;j++){
                auto v=stones[j];
                if(u[0]==v[0] || u[1]==v[1]){
                    ds.unionBySize({u[0],u[1]},{v[0],v[1]});
                }
            }
        }
        int comp=0;
        for(auto it:ds.parent){
            if(it.first==it.second)     comp++;
        }
        return n-comp;
    }
};
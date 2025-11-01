class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);  // for 1 base indexing
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++)    parent[i]=i;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }else{
                    ds.unionBySize(mp[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>>merged(n);
        for(auto it:mp){
            string mail=it.first;
            int node=ds.findParent(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()!=0){
                sort(merged[i].begin(),merged[i].end());
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                for(auto it:merged[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
















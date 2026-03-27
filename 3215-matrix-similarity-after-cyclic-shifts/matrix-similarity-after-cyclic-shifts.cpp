class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        // vector<vector<int>>v=mat;
        // for(int i=0;i<n;i++){
        //     if(i%2==0){
        //         reverse(v[i].begin(),v[i].begin()+k);
        //         reverse(v[i].begin()+k,v[i].end());
        //         reverse(v[i].begin(),v[i].end());
        //     }else{
        //         reverse(v[i].begin(),v[i].end());
        //         reverse(v[i].begin(),v[i].begin()+k);
        //         reverse(v[i].begin()+k,v[i].end());
        //     }
        // }
        // if(mat==v)  return true;
        // else    return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur=j;
                int future;
                if(i%2==0){
                    future=(j+k)%m;
                }else{
                    future=(j-k+m)%m;
                }
                if(mat[i][cur]!=mat[i][future])   return false;
            }
        }
        return true;
    }
};
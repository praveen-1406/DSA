class Solution {
    // int t[1001][1001];
    // bool check(string &s,int i,int j){
    //     if(i>j){
    //         return true;
    //     }
    //     if(t[i][j]!=-1)     return t[i][j];
    //     if(s[i]==s[j]){
    //         return t[i][j]= check(s,i+1,j-1);
    //     }
    //     return t[i][j]= false;
    // }

    int count;

    void check(string &s,int i,int j,int n){
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        // memset(t,-1,sizeof(t));

        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(check(s,i,j)){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // vector<vector<bool>>t(n,vector<bool>(n,false));
        // int count=0;
        // for(int L=1;L<=n;L++){
        //     for(int i=0;i+L-1<n;i++){
        //         int j=i+L-1;
        //         if(i==j)    t[i][j]=true;
        //         else if(i+1==j) t[i][j]=(s[i]==s[j]);
        //         else{
        //             t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
        //         }
        //         if(t[i][j])     count++;
        //     }
        // }
        // return count;
        count=0;
        for(int i=0;i<n;i++){
            check(s,i,i,n);
            check(s,i,i+1,n);
        }
        return count;
    }
};
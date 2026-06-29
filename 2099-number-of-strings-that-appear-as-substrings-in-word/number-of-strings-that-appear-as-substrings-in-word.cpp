class Solution {
    bool check(int n,string&word,string&str){
            for(int i=0;i<n;i++){
                string substr="";
                for(int j=i;j<n;j++){
                    substr+=word[j];
                    if(str==substr)     return true;
                }
            }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0,n=word.size();
        for(auto str:patterns){
            if(check(n,word,str))   cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int cnt=0,f=startIndex,b=startIndex;
        for(;cnt<n;cnt++,f=(f+1)%n,b=(b-1+n)%n){
            if(target==words[f]){
                return min(cnt,n-cnt);
            }
            if(target==words[b]){
                return min(cnt,n-cnt);
            }
        }
        return -1;

    }
};
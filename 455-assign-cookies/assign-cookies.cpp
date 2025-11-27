class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gp=g.size()-1;
        int sp=s.size()-1;
        int cnt=0;
        while(gp>=0 && sp>=0){
            if(g[gp]>s[sp]) gp--;
            else if(g[gp]<=s[sp]){
                gp--;
                sp--;
                cnt++;
            }
        }
        return cnt;
    }
};
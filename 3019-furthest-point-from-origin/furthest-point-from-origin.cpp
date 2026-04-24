class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,u=0;
        for(auto i:moves){
            if(i=='L')  l++;
            else if(i=='R')     r++;
            else    u++;
        }
        return max(l+u-r,r+u-l);
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<=2)    return n;
        int b1=0,b2=0;
        int l=0,r=0,maxFruits=0;
        while(r<n){
            if(fruits[r]!=fruits[b1] && fruits[r]!=fruits[b2]){
                int x=(b1>=b2)?b2:b1;
                if(b1!=b2)    l=x+1;
                b1=r-1;
                b2=r;
            }
            if(fruits[r]==fruits[b1])   b1=r;
            if(fruits[r]==fruits[b2])   b2=r;
            maxFruits=max(maxFruits,r-l+1);
            r++;
        }
        return maxFruits;
    }
};
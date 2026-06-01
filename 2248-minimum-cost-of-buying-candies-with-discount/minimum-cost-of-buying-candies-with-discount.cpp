class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=0;
        if(n<=2){
            for(auto i:cost)    ans+=i;
            return ans;
        }
        sort(cost.begin(),cost.end(),greater<int>());
        int i=0;
        for(;i<n-2;i+=3){
            ans+=cost[i]+cost[i+1];
        }
        while(i<n) {
            ans+=cost[i];
            i++;
        }
        return ans;
    }
};
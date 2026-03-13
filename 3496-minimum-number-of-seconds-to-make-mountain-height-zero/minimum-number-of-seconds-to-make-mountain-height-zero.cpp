class Solution {
    typedef long long ll;
public:
    bool check(ll mid,int mh, vector<int>& workerTimes){
        ll h=0;
        for(auto t:workerTimes){
            h+=(ll)(sqrt(2*mid/t+0.25)-0.5);
            if(h>=mh)   return true;
        }
        return h>=mh;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime=*max_element(workerTimes.begin(),workerTimes.end());
        ll l=1;
        ll r=(ll)maxTime*mountainHeight*(mountainHeight+1)/2;

        ll result=0;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(check(mid,mountainHeight,workerTimes)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};
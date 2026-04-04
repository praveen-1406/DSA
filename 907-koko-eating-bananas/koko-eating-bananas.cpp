class Solution {
    long long func(vector<int>& piles, int hours){
        long long thrs=0;
        for(int i=0;i<piles.size();i++){
            thrs+=(piles[i]+hours-1)/hours;
        }
        return thrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(int i=0;i<piles.size();i++)     high=max(high,piles[i]);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long thrs=func(piles,mid);

            if(thrs<=h)     high=mid-1;
            else    low=mid+1;

        }
        return low;
    }
};
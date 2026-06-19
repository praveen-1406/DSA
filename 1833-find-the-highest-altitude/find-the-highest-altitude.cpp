class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int maxi=0;
        for(auto i:gain){
            alt+=i;
            maxi=max(maxi,alt);
        }
        return maxi;
    }
};
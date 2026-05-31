class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m=mass;
        for(auto as:asteroids){
            if((long long)as>m)     return false;
            m+=as;
        }
        return true;
    }
};
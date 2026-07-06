class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return (a[0]==b[0])? a[1]>b[1] : a[0]<b[0];
        });
        vector<vector<int>>rem;
        for(auto i:intervals){
            int lastInd=rem.size()-1;
            if(rem.empty() || rem[lastInd][1]<i[1]){
                rem.push_back(i);
            }
        }
        return rem.size();
    }
};
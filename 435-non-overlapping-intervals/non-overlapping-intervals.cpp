class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==1)    return 0;
        sort(arr.begin(),arr.end(),[](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
        
        vector<vector<int>>selected;
        selected.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(selected[selected.size()-1][1]<=arr[i][0])   selected.push_back(arr[i]);
        }
        int cnt=n-selected.size();
        return cnt;
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        if(n==1)    return 0;
        sort(arr.begin(),arr.end(),[](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
        int cnt=0;
        int lastVal=arr[0][1];
        for(int i=1;i<n;i++){
            if(lastVal>arr[i][0])   cnt++;
            else    lastVal=arr[i][1];
        }
        return cnt;
    }
};
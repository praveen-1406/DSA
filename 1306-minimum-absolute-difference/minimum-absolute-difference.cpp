class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        int a=0;
        int b=1;
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mdiff=INT_MAX;
        while(b<n){
            mdiff=min(mdiff,abs(arr[b]-arr[a]));
            a++;
            b++;
        }
        a=0;
        b=1;
        while(b<n){
            if(mdiff==abs(arr[b]-arr[a]))   ans.push_back({arr[a],arr[b]});
            a++;
            b++;
        }
        return ans;
    }
};
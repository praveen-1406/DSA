class Solution {
public:
    int M=(int)1e9+7;
    vector<int>findNSE(vector<int>& arr){
        int n=arr.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findPSE(vector<int>& arr){
        int n=arr.size();
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findNSE(arr);
        vector<int>pse=findPSE(arr);
        int total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(right*left*1LL*arr[i])%M)%M;
        }
        return total;
    }
};
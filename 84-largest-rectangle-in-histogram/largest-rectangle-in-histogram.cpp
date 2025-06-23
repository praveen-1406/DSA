class Solution {
public:
    vector<int>findNSE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findPSE(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse=findNSE(heights);
        vector<int>pse=findPSE(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            maxArea=max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};
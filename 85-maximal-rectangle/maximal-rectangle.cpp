class Solution {
public:
    int areaLargestRectHist(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int el=st.top();
                st.pop();
                int nse=i,pse=(st.empty())?-1:st.top();
                maxArea=max(maxArea,(nse-pse-1)*heights[el]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=st.top();
            st.pop();
            int nse=n,pse=(st.empty())?-1:st.top();
            maxArea=max(maxArea,(nse-pse-1)*heights[el]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>pSum(n,vector<int >(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum=0;
                pSum[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,areaLargestRectHist(pSum[i]));
        }
        return maxArea;
    }
};
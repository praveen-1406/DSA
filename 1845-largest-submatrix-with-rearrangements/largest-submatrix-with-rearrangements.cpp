class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int maxArea=0;

        vector<int>preRow(n,0);

        for(int row=0;row<m;row++){
            vector<int>curRow=matrix[row];
            for(int col=0;col<n;col++){
                if(curRow[col]==1){
                    // matrix[row][col]+=matrix[row-1][col];  //Cummulative ones
                    curRow[col]+=preRow[col];  //Cummulative ones
                }
            }
            vector<int>heights=curRow;
            sort(begin(heights),end(heights),greater<int>());
            for(int i=0;i<n;i++){
                int base=(i+1);
                int height=heights[i];
                maxArea=max(maxArea,base*height);
            }
            preRow=curRow;
        }

        return maxArea;

    }
};